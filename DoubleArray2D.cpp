#include "DoubleArray2D.h"

#ifdef  _DEBUG
#include <stdio.h>
#include <assert.h>
#endif

DoubleArray2D::DoubleArray2D()
{
    dataPtr       = 0;
    index1Size    = 0;
    index2Size    = 0;
};


DoubleArray2D::DoubleArray2D(long m, long n)
{
    dataPtr       = 0;
    index1Size    = 0;
    index2Size    = 0;
    initialize(m,n);
};

DoubleArray2D::DoubleArray2D(double* d, long m, long n)
{
    dataPtr       = 0;
    index1Size    = 0;
    index2Size    = 0;
    initialize(d,m,n);
};

DoubleArray2D::DoubleArray2D(const DoubleArray2D& D)
{
    index1Size    = D.index1Size;
    index2Size    = D.index2Size;

	dataPtr       = new double[index1Size*index2Size];
	long i;
	for(i = 0; i < index1Size*index2Size; i++) 
	{dataPtr[i] = D.dataPtr[i];}
};
    
DoubleArray2D::~DoubleArray2D()
{
    if(dataPtr !=  0) delete [] dataPtr;
}

void DoubleArray2D::initialize(long m, long n)
{

    if((index1Size != m)||(index2Size != n))
    {
        delete [] dataPtr;
        dataPtr = new double[m*n];
    }
    index1Size    = m;
    index2Size    = n;

	long i;
	for(i = 0; i < index1Size*index2Size; i++) 
	{dataPtr[i] = 0.0;}
};
    
void DoubleArray2D::initialize(double* d, long m, long n)
{
    initialize(m,n);
    
	long i;
    for(i = 0; i < index1Size*index2Size; i++) 
	{
        dataPtr[i] = d[i];
    }
};

//
//###################################################################
//                  Element Access 
//###################################################################
//

#ifdef _DEBUG

double& DoubleArray2D::operator()(long i1, long i2)
{
    boundsCheck(i1, 0, index1Size-1,1);
    boundsCheck(i2, 0, index2Size-1,2);
    return *(dataPtr +  i2 + i1*index2Size);
};

const double& DoubleArray2D::operator()(long i1, long i2) const
{
    boundsCheck(i1, 0, index1Size-1,1);
    boundsCheck(i2, 0, index2Size-1,2);
    return *(dataPtr +  i2 + i1*index2Size);
};

#else

double& DoubleArray2D::operator()(long i1, long i2)
{
    return *(dataPtr +  i2 + i1*index2Size);
};
    
const double& DoubleArray2D::operator()(long i1, long i2) const
{
    return *(dataPtr +  i2 + i1*index2Size);
};

#endif


DoubleArray1D  DoubleArray2D::row(long i)
{
  DoubleArray1D y(index2Size);
  DoubleArray2D R(*this);
  for (long j=0; j<index2Size; j++)
    {
      y(j) = R(i,j);
    }

  return y;
}

void DoubleArray2D::setrow(long i, const DoubleArray1D& x)
{
  for (long j=0; j<index2Size; j++)
    {
      dataPtr[j+i*index2Size] = x(j);
    }

}

DoubleArray1D  DoubleArray2D::column(long j)
{
  DoubleArray1D y(index1Size);
  DoubleArray2D R(*this);
  for (long i=0; i<index1Size; i++)
    {
      y(i) = R(i,j);
    }
  
  return y; 
}

void DoubleArray2D::setcolumn(long j, const DoubleArray1D& x)
{
  for (long i=0; i<index2Size; i++)
    {
      dataPtr[j+i*index2Size] = x(i);
    }

}

//
//###################################################################
//                     Array Operators
//###################################################################
//

DoubleArray2D DoubleArray2D::operator+(const DoubleArray2D& D)
{
	#ifdef _DEBUG 
    sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	#endif
    DoubleArray2D R(*this);
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {
    R.dataPtr[i] += D.dataPtr[i];
    }
    return R;
}

DoubleArray2D DoubleArray2D::operator-(const DoubleArray2D& D)
{
	#ifdef _DEBUG 
    sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	#endif
    DoubleArray2D R(*this);
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {
    R.dataPtr[i] -= D.dataPtr[i];
    }
    return R;
}

DoubleArray2D DoubleArray2D::operator*(double alpha)
{
    DoubleArray2D R(*this);
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {
    R.dataPtr[i] *= alpha;
    }
    return R;
}

DoubleArray2D operator*(double alpha, const DoubleArray2D& D)
{
    DoubleArray2D R(D);
    long i;
    for(i = 0; i < D.index1Size*D.index2Size; i++)
    {
    R.dataPtr[i] *= alpha;
    }
    return R;
}

DoubleArray1D DoubleArray2D::operator*(const DoubleArray1D& x)
{
    DoubleArray1D y(index1Size);
    DoubleArray2D R(*this);
    
    int rows = (int) this->getIndex1Size();
    int cols = (int) this->getIndex2Size();
    
    for(int ii=0; ii<rows; ii++)
    {
        y(ii) = 0;
        for(int jj=0; jj<cols; jj++)
        {
            y(ii) += x(jj) * R(ii,jj);
        }
    }
    
    return y;
}
    
DoubleArray2D DoubleArray2D::operator/(double alpha)
{
    DoubleArray2D R(*this);
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {
    R.dataPtr[i] /= alpha;
    }
    return R;
}

void DoubleArray2D::operator=(const DoubleArray2D& D)
{
	#ifdef _DEBUG 
	if(index1Size != 0)
	{
        sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	}
	#endif


	if(index1Size*index2Size == 0)
	{
        initialize(D.index1Size,D.index2Size);
    
        index1Size    = D.index1Size;
        index2Size    = D.index2Size;
    }

    long i;
    for(i = 0; i < D.index1Size*D.index2Size; i++)
    {dataPtr[i] = D.dataPtr[i];}
}

void DoubleArray2D::operator*=(double alpha)
{
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {dataPtr[i] *= alpha;}
}

void DoubleArray2D::operator+=(const DoubleArray2D& D)
{
	#ifdef _DEBUG 
	if(index1Size != 0)
	{
    sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	}
	#endif
	if(index1Size*index2Size == 0)
	{initialize(D.index1Size,D.index2Size);}

    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {dataPtr[i] += D.dataPtr[i];}
}
    
void DoubleArray2D::operator-=(const DoubleArray2D& D)
{
	#ifdef _DEBUG 
	if(index1Size != 0)
	{
        sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	}
	#endif
	if(index1Size*index2Size == 0)
	{initialize(D.index1Size,D.index2Size);}

    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {dataPtr[i] -= D.dataPtr[i];}
}

void DoubleArray2D::setToValue(double d)
{
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {dataPtr[i] = d;}
}

double DoubleArray2D::dot(const DoubleArray2D& D) const
{
	#ifdef _DEBUG 
    sizeCheck(this->index1Size,D.index1Size, this->index2Size,D.index2Size);
	#endif

    double R;
    R  = 0;
    long i;
    for(i = 0; i < index1Size*index2Size; i++)
    {R += dataPtr[i]*D.dataPtr[i];}
    return R;
}

//  Input/Output
ostream& operator<<(ostream& outStream, const DoubleArray2D& A)
{
    long i; long j;
    for(i = 0; i < A.index1Size; i++)
    {
        for(j = 0; j < A.index2Size; j++)
        {
            outStream <<  setw(5) << A(i,j) << " ";
        }
        outStream << endl;
    }
    return outStream;

}
//
//###################################################################
//                      Bounds Checking
//###################################################################
//

#ifdef _DEBUG 
void DoubleArray2D::boundsCheck(long i, long begin, long end, int coordinate)
{
    if((i < begin)||(i  > end))
    {
        printf("Array index %d out of bounds \n",coordinate);
        printf("Offending index value %d : Acceptable Range [%d, %d] \n",i, begin, end);
        assert(0);
    }
}
#else
void boundsCheck(long, long, long, int){};
#endif


#ifdef _DEBUG 
void DoubleArray2D::sizeCheck(long Msize1, long Msize2, long Nsize1, long Nsize2)
{
    if(Msize1 != Msize2)
    {
        printf("1st Dimension Sizes Are Incompatable  %d != %d \n" , Msize1, Msize2);
        assert(0);
    }
	if(Nsize1 != Nsize2)
    {
        printf("2nd Dimension Sizes Are Incompatable  %d != %d \n" , Nsize1, Nsize2);
        assert(0);
    }
}
#else
void DoubleArray2D::sizeCheck(long, long, long, long){}
#endif



 
