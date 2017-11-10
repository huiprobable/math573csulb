#include <iostream>
#include <iomanip>
#include "NumericalLinearAlgebra.h"
using namespace std;

Relaxation::Relaxation()
{
    initialize();
}

Relaxation::Relaxation(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    initialize(A_cp, b_cp);
}

void Relaxation::initialize()
{
    A = SparseMatrix();
    b = DoubleArray1D();
    x = DoubleArray1D();
    A_diag = DoubleArray1D();
}

void Relaxation::initialize(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    A = SparseMatrix(A_cp);
    b = DoubleArray1D(b_cp);
    x = DoubleArray1D(b.getSize());
    A_diag = DoubleArray1D(b.getSize());
    for (int i = 0; i < b.getSize(); i++)
    {
        A_diag(i) = A(i,i);
    }
}

int Relaxation::solve(int n, double tol, bool output_msg)
{
    int iter = 0;
    double residue = (b-A*x).norm(2);
    while (iter < n && residue > tol)
    {
        advanceStep();
        iter ++;
        residue = (b-A*x).norm(2);
        if (output_msg)
            cout<<iter<<" "<<residue<<endl;
    }
    if (iter<n && residue<tol)
        return 1;
    return 0;
}

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

GaussSeidel::GaussSeidel()
{
    // add your code here.
    initialize();
    x = DoubleArray1D();
};

GaussSeidel::GaussSeidel(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    // add your code here.
    initialize(A_cp, b_cp);
    x = DoubleArray1D(A_cp.getSize1());
};

void GaussSeidel::advanceStep()
{
    // add your code here.
    for (int i = 0; i < A.getSize1(); i++)
    {
        x(i) = x(i)+(b(i)-A.getRow(i).dot(x))/A_diag(i);
    }
}




