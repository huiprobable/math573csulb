#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"
using namespace std;

template <typename T> int sgn(T val);

int main()
{
    srand(time(NULL));
    
    long n = 40;  // the size of the matrix is n by n.
    long m = 30000;   // this line is related to Lab5, not related to lab4.
    SparseMatrix A(n, n);   // construct A as an n by n sparse matrix.
    DoubleArray1D v(n);     // construct v as a DoubleArray1D of size n, this sets up for lab5.
    
    // Here is Lab 4 code, create the matrix A. 
    for (int i=0; i<n; i++)
    {
    	if (i==0)
    	{
    		A.addEntry(i,i,2.0);
    		A.addEntry(i,i+1,-1.0);
    	}
    	else if (i==n-1)
    	{
    		A.addEntry(i,i,2.0);
    		A.addEntry(i,i-1,-1.0);
    	}
    	else
    	{
    	A.addEntry(i,i,2.0);
    	A.addEntry(i,i-1,-1.0);
    	A.addEntry(i,i+1,-1.0);
    	}
    }
    // This for loop sets the vector v as a random vector. 
    for (int i = 0; i < n; i++)
    {
	v(i) = (rand()%1001)/1000.0-0.5;
    }
    // Please insert your code starting from here.


    // Please insert your code above this line
    
    return 0;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
