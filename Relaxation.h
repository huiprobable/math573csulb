#ifndef __Relaxation__
#define __Relaxation__

#include <iostream>
#include <iomanip>
#include "SparseMatrix.h"
using namespace std;

class Relaxation
{
public :
    Relaxation();
    Relaxation(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    void initialize();
    void initialize(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void advanceStep(){};
    int solve(int n, double eps, bool output_msg);
    
protected:
    SparseMatrix A;
    DoubleArray1D b;
    DoubleArray1D x;
    DoubleArray1D A_diag;
};

#endif
