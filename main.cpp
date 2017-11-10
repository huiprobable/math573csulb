#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "NumericalLinearAlgebra.h"
using namespace std;

template <typename T> int sgn(T val);

int main()
{
    srand(time(NULL));
    
    long n = 40;  // the size of the matrix is n by n.
    long m = 30000;
    SparseMatrix A(n, n);   // construct A as an n by n sparse matrix.
    DoubleArray1D b(n);     // construct b as a DoubleArray1D of size n.
    
    // create the matrix A.
    for (int i=0; i<n; i++)
    {
    	if (i==0)
    	{
    		A.addEntry(i,i,3);
    		A.addEntry(i,i+1,-1.0);
    	}
    	else if (i==n-1)
    	{
    		A.addEntry(i,i,3);
    		A.addEntry(i,i-1,-1.0);
    	}
    	else
    	{
            A.addEntry(i,i,3);
            A.addEntry(i,i-1,-1.0);
            A.addEntry(i,i+1,-1.0);
    	}
    }
    // This for loop sets the vector v as a random vector.
    for (int i = 0; i < n; i++)
    {
        b(i) = (rand()%1001)/1000.0-0.5;
    }
    
    // solve Ax = v using Jacobi method. After you implement Gauss Seidel class, you may change it to Gauss Seidel and see how does Gauss Seidel behave. 
    bool output_msg = 1;
    SteepestDescent J(A,b);
    J.solve(m, 1e-8, output_msg);
    
    return 0;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
