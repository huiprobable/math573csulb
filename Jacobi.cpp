#include <iostream>
#include <iomanip>
#include "Jacobi.h"
using namespace std;

Jacobi::Jacobi()
{
    initialize();
    x_tmp = DoubleArray1D();
};

Jacobi::Jacobi(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    initialize(A_cp, b_cp);
    x_tmp = DoubleArray1D(A_cp.getSize1());
};

void Jacobi::advanceStep()
{
    for (int i = 0; i < A.getSize1(); i++)
    {
        x_tmp(i) = x(i)+(b(i)-A.getRow(i).dot(x))/A_diag(i);
    }
    x = x_tmp;
}

