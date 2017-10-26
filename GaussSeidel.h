#ifndef __GaussSeidel_h__
#define __GaussSeidel_h__

#include <iostream>
#include <iomanip>
#include "Relaxation.h"
using namespace std;

class GaussSeidel: public Relaxation
{
public :
    GaussSeidel();
    GaussSeidel(const SparseMatrix& A_cp, const DoubleArray1D& b_cp);
    virtual void advanceStep();
};

#endif
