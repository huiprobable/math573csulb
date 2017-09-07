#ifndef __DoubleArray1D__
#define __DoubleArray1D__

#include <iostream>
#include <iomanip>
using namespace std;

class DoubleArray1D 
{
public :
//
//###################################################################
//                 Constructors/Initialization
//###################################################################
//
    DoubleArray1D();
    DoubleArray1D(long m);
    DoubleArray1D(double* d, long m);
    DoubleArray1D(const DoubleArray1D& D);
    ~DoubleArray1D();
    void initialize(long m);
    void initialize(double* d, long m);

//
//###################################################################
//                  Element Access 
//###################################################################
//

#ifdef _DEBUG 
    double&  operator()(long i1);
    const double&  operator()(long i1) const;
#else
    double&  operator()(long i1);
    const double&  operator()(long i1) const;
#endif

//
//###################################################################
//                Array Structure Access Functions
//###################################################################
//

    double* getDataPointer(){return dataPtr;};
    long getIndex1Size()  const {return index1Size;}

//
//  Get/Set specifically for one dimensional arrays
//
    long getSize()       const {return index1Size;}

    //
    // Resizes array to exactly newSize
    //
    void resize(long newSize);

//
//###################################################################
//                     Array Operators
//###################################################################
//
    DoubleArray1D operator+(const DoubleArray1D& D);
    DoubleArray1D operator-(const DoubleArray1D& D);
    DoubleArray1D operator*(double alpha);
    friend DoubleArray1D operator*(double alpha, const DoubleArray1D& D);
    DoubleArray1D operator/(double alpha);
    
//
//###################################################################
//          
//###################################################################
//
    void operator=(const DoubleArray1D& D);
    void operator*=(double alpha);
    void operator+=(const DoubleArray1D& D);
    void operator-=(const DoubleArray1D& D);
    void setToValue(double d);
    double dot(const DoubleArray1D& B) const;

//
//  Output
//
    friend ostream& operator<<(ostream& outStream, const DoubleArray1D& V);
    
//
//###################################################################
//                      Class Data Members
//###################################################################
//
    protected :

    double*      dataPtr;     // data pointer
    long    index1Size;       // coordinate 1 size

//
//###################################################################
//                      Bounds Checking
//###################################################################
//

    static void boundsCheck(long, long, long, int);
    static void sizeCheck(long, long);

    
};

#endif


 
