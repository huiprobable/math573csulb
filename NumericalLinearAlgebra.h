#ifndef __NumericalLinearAlgebra_H__
#define __NumericalLinearAlgebra_H__

#include <iostream>
#include <iomanip>
#include "LinearAlgebra.h"

// Relaxation methods:

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

class Jacobi: public Relaxation   // Relaxation is a base class; Jacobi is a derived class.
{
public :
    Jacobi();
    Jacobi(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void advanceStep();
    
private:
    DoubleArray1D x_tmp;
};

class GaussSeidel: public Relaxation
{
public :
    GaussSeidel();
    GaussSeidel(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void advanceStep();
};

// One dimensional Projection methods:

class Projection
{
public:
    Projection();
    Projection(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    ~Projection();
    void initialize();
    void initialize(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void update_VW(){};
    virtual void update_x();
    int solve(int n, double eps, bool output_msg);
    
protected:
    SparseMatrix A;
    DoubleArray1D b;
    DoubleArray1D x;
    DoubleArray1D r;
    DoubleArray1D* W;
    DoubleArray1D* V;
    int dim_K;
};

class SteepestDescent: public Projection
{
    public :
    SteepestDescent();
    SteepestDescent(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void update_VW();
    
private:
    DoubleArray1D p;
};

class MinimalResidual: public Projection
{
    public :
    MinimalResidual();
    MinimalResidual(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void update_VW();
    
private:
    DoubleArray1D p;
};

class ResNormSteepestDescent: public Projection
{
    public :
    ResNormSteepestDescent();
    ResNormSteepestDescent(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void update_VW();
    
private:
    DoubleArray1D p;
};

#endif
