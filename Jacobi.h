#ifndef __Jacobi_h__
#define __Jacobi_h__

#include <iostream>
#include <iomanip>
#include "Relaxation.h"
using namespace std;

class Jacobi: public Relaxation   // Relaxation is a base class; Jacobi is a derived class. 
{
public :
    Jacobi();
    Jacobi(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void advanceStep();
    
private:
    DoubleArray1D x_tmp;
};

#endif
