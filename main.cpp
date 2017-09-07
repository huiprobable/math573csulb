#include <iostream>
#include "DoubleArray1D.h"
#include "DoubleArray2D.h"
using namespace std;

int main()
{
    /*
    int n = 5;
    DoubleArray2D A(n, n);   // Declaring matrix A to be n by n.
    DoubleArray2D B(n, n);   // Declaring matrix B to be n by n.
    DoubleArray1D x(n);      // Declaring vector x to be size n.
    B.setToValue(1.0);      // Set value B_ij=1.0 for all i, j.
    x.setToValue(2.0);      // Set value x_i=2.0 for all i.
    for (int i = 0; i<n-1; i++)
    {
        A(i, i) = 2;        // Set all diagonal entries of A to be 2.
        A(i, i+1) = -1;     // Set all diagonal+1 level entries of A to be -1.
        A(i+1, i) = -1;     // Set all diagonal-1 level entries of A to be -1.
    }
    A(n-1,n-1) = 2;         // Set the (n,n)-th entry of A to be 2.
    A += B;                 // A = A+B
    DoubleArray1D y(n);     // Declare y to be a vector of size n.
    y = A*x;                // Compute y = A*x using the member function you write.
    cout << A << "\n .* \n"<< x <<"\n =\n"<<y<<"\n\n"; // print to the console screen.
    */
    
#ifdef _WIN32
    system("pause");
#endif
    return 0;
}
