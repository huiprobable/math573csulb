#ifndef __SparseMatrix__
#define __SparseMatrix__

#include <iostream>
#include <iomanip>
#include "DoubleArray1D.h"
#include "SparseRow.h"
using namespace std;

class SparseMatrix
{
public :
//
//###################################################################
//                 Constructors/Initialization
//###################################################################
//
    SparseMatrix();
    SparseMatrix(long m, long n);
    SparseMatrix(const SparseMatrix& D);
    ~SparseMatrix();
    void initialize(long m, long n);
    
//
//###################################################################
//                  Element Access
//###################################################################
//
    
    double  operator()(long i1, long i2);
    SparseRow&  operator()(long i1);
    const SparseRow&  operator()(long i1) const;

//
//###################################################################
//                Array Structure Access Functions
//###################################################################
//
    
    const SparseRow& getRow(long i){return rows[i];};
    long getSize1() const {return size1;};
    long getSize2() const {return size2;};
    void addEntry(long i, long j, double v);
    
//
//###################################################################
//                     Array Operators
//###################################################################
//
    SparseMatrix operator+(const SparseMatrix& D);
    SparseMatrix operator-(const SparseMatrix& D);
    SparseMatrix operator*(double alpha);
    friend SparseMatrix operator*(double alpha, const SparseMatrix& D);
    SparseMatrix operator/(double alpha);
    
    void operator=(const SparseMatrix& D);
    void operator*=(double alpha);
    void operator+=(const SparseMatrix& D);
    void operator-=(const SparseMatrix& D);
    DoubleArray1D operator*(const DoubleArray1D& B) const;
    
//
//  Output
//
    friend ostream& operator<<(ostream& outStream, const SparseMatrix& V);
    
//
//###################################################################
//                      Class Data Members
//###################################################################
//
protected:
    long size1;
    long size2;
    SparseRow* rows;
};

#endif
