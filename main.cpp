#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "DoubleArray1D.h"
#include "DoubleArray2D.h"
using namespace std;

template <typename T> int sgn(T val);

int main()
{
    srand(time(NULL));
    int n=5,m=3;
    DoubleArray2D x(n,m);   // declare x to be an n-by-m matrix.
    for (int j=0; j<m; j++)
    {
        for (int i=0; i<n; i++)
        {
            x(i,j) = (rand()%1000)/1000.0-0.5;
        }
    }

    DoubleArray2D X(x);
    cout<< "x=\n" << x<<"\n\n";

    // Householder process, we want to orthogonalize the m columns of the matrix x. 

    DoubleArray2D w(n,m);
    DoubleArray2D q(n,m);
    DoubleArray2D r(m,m);
    DoubleArray1D e(n);
    for (int k=0; k<m; k++)
    {
        for (int i=0; i<k; i++)
        {
            x.setcolumn(k, x.column(k)-2*w.column(i).dot(x.column(k))*w.column(i));  // compute r_k = P_{k-1}...P_1*x_k
        }
        double wk_norm = 0.0;
        for (int j=0; j<n; j++)
        {
            if (j<k)
            {
                w(j,k) = 0.0;
            }
            else
            {
                w(j,k) = x(j,k);
                wk_norm += pow(x(j,k),2.0);                            // compute w_k using (1.24)
            }
        }
        wk_norm = pow(wk_norm,0.5);
        
        // Here, add a few lines to modify w(k,k) and to normalize w_k, according to (1.25) and (1.23) from the book
        
        
        for (int i = 0; i < m; i++)
        {
            if (i<k)
            {
                r(i,k) = x(i,k);                                       // compute r_k = P_k*r_k
            }
            else
            {
                r(i,k) = 0;                                            // compute r_k = P_k*r_k
            }
        }
        r(k,k) = -sgn<double>(x(k,k))*wk_norm;                         // compute r_k = P_k*r_k
        for (int j=0; j<n; j++)
        {
            e(j) = 0.0;
        }
        e(k) = 1.0;
        for (int i=k; i>=0; i--)
        {
            // Here, add one line that does e = P_k*e, where P_k = I-2w_k*w_k^T
        }
        q.setcolumn(k, e);
    }


    cout.precision(3);
    cout<<"q = \n"<<q<<"\n\n";
    cout<<"w = \n"<<w<<"\n\n";
    cout<<"r = \n"<<r<<"\n\n";
    cout<<"x-qr = \n"<<X-q*r<<"\n\n";
    cout<<"q columns dot products: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<q.column(i).dot(q.column(j))<<" ";
        }
    }
    cout<<"\n";
    
#ifdef _WIN32
    system("pause");
#endif
    return 0;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
