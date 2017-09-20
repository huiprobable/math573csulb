#ifndef __DoubleArray2D__
#define __DoubleArray2D__

#include <iostream>
#include <iomanip>
using namespace std;

#include "DoubleArray1D.h"

class DoubleArray2D 
{

public :
//
//###################################################################
//                 Constructors/Initialization
//###################################################################
//
    DoubleArray2D();
    DoubleArray2D(long m, long n);
    DoubleArray2D(double* d, long m, long n);
    DoubleArray2D(const DoubleArray2D& D);
    ~DoubleArray2D();
    void initialize(long m, long n);
    void initialize(double* d, long m, long n);
//
//###################################################################
//                  Element Access 
//###################################################################
//
    double&  operator()(long i1, long i2);
    const double&  operator()(long i1, long i2) const;
    DoubleArray1D row(long i);
    void setrow(long i, const DoubleArray1D& x);
    DoubleArray1D  column(long j);
    void setcolumn(long j, const DoubleArray1D& x);


//
//###################################################################
//                Array Structure Access Functions
//###################################################################
//
    double* getDataPointer(){return dataPtr;};
    long getIndex1Size()  const {return index1Size;}
    long getIndex2Size()  const {return index2Size;}

//
//###################################################################
//                     Array Operators
//###################################################################
//

    DoubleArray2D operator+(const DoubleArray2D& D);
    DoubleArray2D operator-(const DoubleArray2D& D);
    DoubleArray2D operator*(double alpha);
    DoubleArray1D operator*(const DoubleArray1D& x);
    DoubleArray2D operator*(const DoubleArray2D& D);
    friend DoubleArray2D operator*(double alpha, const DoubleArray2D& D);
    DoubleArray2D operator/(double alpha);
    void operator=(const DoubleArray2D& D);
    void operator*=(double alpha);
    void operator+=(const DoubleArray2D& D);
    void operator-=(const DoubleArray2D& D);
    void setToValue(double d);
    double dot(const DoubleArray2D& D) const;

//  Input/Output
    friend ostream&  operator <<(ostream& outStream, const DoubleArray2D& A);
    
//
//###################################################################
//                      Class Data Members
//###################################################################
//
    protected :

    double*      dataPtr;     // data pointer
    long      index1Size;     // coordinate 1 size
    long      index2Size;     // coordinate 2 size

//
//###################################################################
//                      Bounds Checking
//###################################################################
//

    static void boundsCheck(long, long, long, int);

    static void sizeCheck(long, long, long, long);
    
};

#endif


 
