#include <iostream>
#include <iomanip>
#include "NumericalLinearAlgebra.h"
using namespace std;

Projection::Projection()
{
    initialize();
}

Projection::Projection(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    dim_K = 0;
    initialize(A_cp, b_cp);
}

Projection::~Projection()
{
    if( W != NULL)
    {
        delete [] W;
    }
    if( V != NULL)
    {
        delete [] V;
    }
}

void Projection::initialize()
{
    A = SparseMatrix();
    b = DoubleArray1D();
    x = DoubleArray1D();
    r = DoubleArray1D();
    dim_K = 0;
    V = NULL;
    W = NULL;
}

void Projection::initialize(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    A = SparseMatrix(A_cp);
    b = DoubleArray1D(b_cp);
    x = DoubleArray1D(b.getSize());
    r = b - A*x;
    if (dim_K == 0)
    {
        V = NULL;
        W = NULL;
    }
    else
    {
        V = new DoubleArray1D[dim_K];
        W = new DoubleArray1D[dim_K];
    }
}

void Projection::update_x()
{
    if (dim_K == 1)
    {
        double alpha = W[0].dot(r)/(A*V[0]).dot(W[0]);
        x += alpha*V[0];
    }
}

int Projection::solve(int n, double tol, bool output_msg)
{
    int iter = 0;
    double residue = r.norm(2);
    while (iter < n && residue > tol)
    {
        r = b - A*x;
        update_VW();
        update_x();
        iter ++;
        residue = r.norm(2);
        if (output_msg)
            cout<<iter<<" "<<residue<<endl;
    }
    if (iter<n && residue<tol)
        return 1;
    return 0;
}

SteepestDescent::SteepestDescent()
{
    initialize();
}

SteepestDescent::SteepestDescent(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    dim_K = 1;
    initialize(A_cp, b_cp);
}

void SteepestDescent::update_VW()
{
    V[0] = r;
    W[0] = r;
    p = A*r;
}

MinimalResidual::MinimalResidual()
{
    initialize();
}

MinimalResidual::MinimalResidual(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    dim_K = 1;
    initialize(A_cp, b_cp);
}

void MinimalResidual::update_VW()
{
    V[0] = r;
    p = A*r;
    W[0] = p;
}

ResNormSteepestDescent::ResNormSteepestDescent()
{
    initialize();
}

ResNormSteepestDescent::ResNormSteepestDescent(const SparseMatrix& A_cp, const DoubleArray1D& b_cp)
{
    dim_K = 1;
    initialize(A_cp, b_cp);
}

void ResNormSteepestDescent::update_VW()
{
    p = A.transMultiply(r);
    V[0] = p;
    W[0] = A*p;
}


