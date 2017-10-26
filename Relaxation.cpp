#include <iostream>
#include <iomanip>
#include "Relaxation.h"
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
