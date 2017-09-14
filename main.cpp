#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "DoubleArray1D.h"
#include "DoubleArray2D.h"
using namespace std;

int main()
{
  srand(time(NULL));
  int n=10,m=3;
  DoubleArray2D x(n,m);   // declare x to be an n-by-m matrix. 
  for (int j=0; j<m; j++)
    {
      for (int i=0; i<=j; i++)
	{
	  x(i,j) = (rand()%1000)/1000.0;
	}
    }

  cout<< "x=\n" << x<<"\n\n";

    // Gram-Schmidt process, we want to orthogonalize the m columns of the matrix x. 

  DoubleArray2D q(n,m);   // declare q to be an n-by-m matrix. 
  DoubleArray2D r(m,m);   // declare r to be an m-by-m matrix. 
  r(0,0) = sqrt(x.column(0).dot(x.column(0)));    // This is to set r_00 to be the 2-norm of x_0. 
    
    if (r(0,0) != 0)
    {
      q.setcolumn(0, x.column(0)/r(0,0));     // This is to set q_0 to be x_0/r_00. 
	for (int j = 1; j < m; j++)
	{
	  for (int k = 0; k < j; k++)
	  {
	    //  Please add a line here: r(k,j) = ...
	    //  To compute r_kj = the inner product of x_j and q_k. 
	  }

	  DoubleArray1D q_hat(x.column(j));   // declare q_hat to be a vector equal to x_j. 
	  for (int k = 0; k < j; k++)
	  {
	    // Please add a line here:  q_hat -= ...
	    // Please add a line here:  r(j,j) = ...
	    if (r(j,j) == 0)
	      break;
	    // Please add a line here to set the j-th colume of q to be equal to q_hat/r_jj. 
	  }
	}
    }
    cout<< "r=\n" << r<<"\n\n";
    cout<< "q=\n" << q<<"\n\n";
    
#ifdef _WIN32
    system("pause");
#endif
    return 0;
}
