#ifndef __SparseRow__
#define __SparseRow__

#include <iostream>
#include <iomanip>
#include "DoubleArray1D.h"
using namespace std;

class SparseRow
{
public :
//
//###################################################################
//                 Constructors/Initialization
//###################################################################
//
    SparseRow();
    SparseRow(long m);
    SparseRow(const SparseRow& D);
    ~SparseRow();
    void initialize(long m);
    
//
//###################################################################
//                  Element Access
//###################################################################
//
    
    double  operator()(long i1);

//
//###################################################################
//                Array Structure Access Functions
//###################################################################
//
    
    double* getValue(){return value;};
    long* getIndex(){return index;};
    long getNnz() const {return nnz;};
    long getIndex1Size()  const {return size;};
    void addEntry(long i, double v);
    
//
//###################################################################
//                     Array Operators
//###################################################################
//
    SparseRow operator+(const SparseRow& D);
    SparseRow operator-(const SparseRow& D);
    SparseRow operator*(double alpha);
    friend SparseRow operator*(double alpha, const SparseRow& D);
    SparseRow operator/(double alpha);
    
    void operator=(const SparseRow& D);
    void operator*=(double alpha);
    void operator+=(const SparseRow& D);
    void operator-=(const SparseRow& D);
    double dot(const DoubleArray1D& B) const;
    double norm(double p) const;
    
//
//  Output
//
    friend ostream& operator<<(ostream& outStream, const SparseRow& V);
    
//
//###################################################################
//                      Class Data Members
//###################################################################
//
protected:
    long size;
    long nnz;
    long* index;
    double* value;
};

#endif
