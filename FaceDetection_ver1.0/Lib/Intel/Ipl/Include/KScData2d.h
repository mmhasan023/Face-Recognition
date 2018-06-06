#ifndef __KSDATA2D_H__
#define __KSDATA2D_H__

#include "KScData.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

template <class T>
class KS_CLASS KScData2d : public KScData
{

// attribute
public:
	
	T*  pBuffer;
	T** pArray;

// methods
public:

	KScData2d(void) 
	{
		id  = KS_DATA_2D + sizeof(T);
		dz  = 1;
		dim = 2;
		bpu = sizeof(T);

		pBuffer = NULL;
		pArray  = NULL;
	}

	KScData2d(char *szName) : KScData(szName)
	{
		id  = KS_DATA_2D + sizeof(T);
		
		dz  = 1;
		dim = 2;
		bpu = sizeof(T);
		
//		SetName(name);

		pBuffer = NULL;
		pArray  = NULL;
	}

	KScData2d(char *name, int xSize, int ySize);
	KScData2d(int xSize, int ySize);

	virtual	~KScData2d(void);

	int  Alloc(int xSize, int ySize);
	void Free(void);
	int  Realloc(int xSize, int ySize);

	void SetPixel(T value, int x, int y);
	T    GetPixel(int x, int y);

	int SetRow(T *row, int y, int x, int len);
	int GetRow(T *row, int y, int x, int len);
	T*  GetRow(int y, int x, int len);

	int SetSection(T* section, int x_i, int y_j, int x_size, int y_size);
	int GetSection(T* section, int x_i, int y_j, int x_size, int y_size);
	T*  GetSection(int x_i, int y_j, int x_size, int y_size);

	int GetXSize  (void) { return dx; }
	int GetYSize  (void) { return dy; }

	T*  GetBuffer (void) { return pBuffer; }

	T** Make2dArray(void);
	int RemoveArray(void);
	T** Get2dArray(void) { return pArray; }

	KScData2d<T> &operator=(KScData2d<T> &from_d2p);
};

template <class T> 
KScData2d<T>::KScData2d(char *name, int xSize, int ySize)
{
	id  = KS_DATA_2D + sizeof(T);

	dx  = xSize;
	dy  = ySize;
	dz  = 1;
	dim = 2;
	bpu = sizeof(T);

	//pBuffer = (T*)malloc(sizeof(T) * dx * dy);
	pBuffer = new T [sizeof(T) * dx * dy];
	if (pBuffer == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return;
	}

	if (Make2dArray() == NULL)
		return;

	if (InitTo(0) != NO_ERROR)
		return;

	statusCode = NO_ERROR;

	SetName(name);
}

template <class T> 
KScData2d<T>::KScData2d(int xSize, int ySize)
{
	id  = KS_DATA_2D + sizeof(T);

	dx  = xSize;
	dy  = ySize;
	dz  = 1;
	dim = 2;
	bpu = sizeof(T);

	//pBuffer = (T*)malloc(sizeof(T) * dx * dy);
	pBuffer = new T [sizeof(T) * dx * dy];
	if (pBuffer == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return;
	}

	if (Make2dArray() == NULL)
		return;

	if (InitTo(0) != NO_ERROR)
		return;

	statusCode = NO_ERROR;
}

template <class T> 
KScData2d<T>::~KScData2d(void)
{
	Free();
}

template <class T> 
int KScData2d<T>::Alloc(int xSize, int ySize)
{
	if (GetBuffer() != NULL)
		return statusCode = ALREADY_ALLOC_MEMORY;
	else
	{
		//pBuffer = (T*)malloc(sizeof(T) * xSize * ySize);
		pBuffer = new T [sizeof(T) * xSize * ySize];
		if (pBuffer == NULL)
			return statusCode = FAIL_ALLOC_MEMORY;
		else
		{
			dx  = xSize;
			dy  = ySize;
			bpu = sizeof(T);

			memset(pBuffer, 0, sizeof(T) * xSize * ySize);

			if (Make2dArray() == NULL)
				return statusCode;
			return statusCode = NO_ERROR;
		}
	}
}

template <class T> 
void KScData2d<T>::Free()
{
	if (Get2dArray() != NULL)
		RemoveArray();

	if (GetXSize()!=0 && GetYSize()!=0 && GetBuffer() != NULL)
		delete pBuffer;
	
	pBuffer = NULL;
	ResetClass();
}

template <class T> 
int KScData2d<T>::Realloc(int xSize, int ySize)
{
	Free();

	return Alloc(xSize, ySize);
}

template <class T> 
T** KScData2d<T>::Make2dArray(void)
{
	if (GetBuffer() == NULL)
	{	
		statusCode = NO_ALLOC_MEMORY;
		return NULL;
	}

	if (Get2dArray() != NULL)
	{
		statusCode = ALREADY_ALLOC_MEMORY_MAP;
		return NULL;
	} 
	else
	{
		//pArray = (T**)malloc(dy * sizeof(T*));
		pArray = new T* [sizeof(T*) * dy];
		if (pArray == NULL)
		{
			statusCode = FAIL_ALLOC_MEMORY_MAP;
			return NULL;
		}
		memset(pArray, 0, sizeof(T*) * dy);

		for (register int i = 0 ; i < dy ; i++)
			pArray[i] = pBuffer + long(dx * i);

		statusCode = NO_ERROR;

		return pArray;
	}
}

template <class T> 
int KScData2d<T>::RemoveArray(void)
{
	if (GetBuffer() == NULL)
		return statusCode = NO_ALLOC_MEMORY;

	if (Get2dArray() == NULL)
		return statusCode = NO_ALLOC_MEMORY_MAP;
	else
	{
		delete pArray;
		pArray = NULL;
		return statusCode = NO_ERROR;
	}
}

template <class T> 
T KScData2d<T>::GetPixel(int x, int y)
{
	if (Get2dArray() != NULL)
		return pArray[y][x];
	else
		return 0x00;
}

template <class T> 
void KScData2d<T>::SetPixel(T value, int x, int y)
{
	if (Get2dArray() != NULL)
		pArray[y][x] = value;
}

template <class T> 
int KScData2d<T>::GetRow(T * row, int y, int x, int len)
{
	if (x < 0 || y < 0 || x > dx || y > dy)
		return statusCode = OUT_OF_RANGE;

	int bound_len;
	if (Get2dArray() != NULL) 
	{
		if (x + len > dx)
		{
			bound_len = dx - x;
			memcpy(row, &pArray[y][x], sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T) * (len - bound_len));
		}
		else
			memcpy(row, &pArray[y][x], sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else if (GetBuffer()!=NULL)
	{
		if (x + len > dx)
		{
			bound_len = dx - x;
			memcpy(row, pBuffer + y * dx + x, sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T) * (len - bound_len));
		}
		else
			memcpy(row, pBuffer + y * dx + x, sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return statusCode;
}

template <class T> 
T* KScData2d<T>::GetRow(int y, int x, int len)
{
	if (x < 0 || y < 0 || x > dx || y > dy)
	{
		statusCode = OUT_OF_RANGE;
		return NULL;
	}

	//T* row = (T*)malloc(len * sizeof(T));
	T* row = new T [len * sizeof(T)];
	if (row == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return NULL;
	}

	int bound_len;
	if (Get2dArray() != NULL) 
	{
		if (x + len > dx)
		{
			bound_len = dx - x;
			memcpy(row, &pArray[y][x], sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T) * (len - bound_len));
		}
		else
			memcpy(row, &pArray[y][x], sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else if (GetBuffer() != NULL)
	{
		if (x + len > dx)
		{
			bound_len = dx - x;
			memcpy(row, pBuffer + y * dx + x, sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T)*(len - bound_len));
		}
		else
			memcpy(row, pBuffer + y * dx + x], sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return row;
}

template <class T> 
int KScData2d<T>::SetRow(T* row, int y, int x, int len)
{
	if (x < 0 || y < 0 || x > dx || y > dy)
		return statusCode = OUT_OF_RANGE;

	if (Get2dArray() != NULL) 
	{
		memcpy(&pArray[y][x], row, sizeof(T) * ((x + len > dx) ? dx - x : len));

		statusCode = NO_ERROR;
	}
	else if (GetBuffer() != NULL)
	{
		memcpy(pBuffer + y * dx + x, row, sizeof(T) * ((x + len > dx) ? dx - x : len));

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return statusCode;
}

template <class T> 
T* KScData2d<T>::GetSection(int x_i, int y_j, int x_size, int y_size)
{
	if (x_i + x_size > dx || y_j + y_size > dy)
	{
		statusCode = NO_SUITABLE_RANGE;

		return NULL;
	}
	else if (x_i < 0 || x_i > dx || y_j < 0 || y_j > dy)
	{
		statusCode = OUT_OF_RANGE;

		return NULL;
	}

	//T* result = (T*)malloc(sizeof(T) * x_size * y_size);
	T* result = new T [sizeof(T) * x_size * y_size];
	if (result == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	

		return NULL;
	}

	// fill in this memory, from bottom to top.  memory should contain
	// bottom row, then second-bottom row, ..., top row.
	for (register int row_idx = 0 ; row_idx < y_size ; row_idx++)
    {
		GetRow(result  + row_idx * x_size, // start of row in memory
			   row_idx + y_j,			   // y pos of row start in image
			   x_i,						   // x pos of row start in image
			   x_size);		      	       // length of row
    }

	return result;
}

template <class T> 
int KScData2d<T>::GetSection(T *result, int x_i, int y_j, int x_size, int y_size)
{
	if (x_i + x_size>dx || y_j + y_size>dy)
		return statusCode = NO_SUITABLE_RANGE;
	else if (x_i < 0 || x_i > dx || y_j < 0 || y_j > dy)
		return statusCode = OUT_OF_RANGE;

	// fill in this memory, from bottom to top.  memory should contain
	// bottom row, then second-bottom row, ..., top row.
	for (register int row_idx = 0 ; row_idx < y_size ; row_idx++)
    {
		GetRow(result + row_idx * x_size, // start of row in memory
			   row_idx+y_j,				  // y pos of row start in image
			   x_i,						  // x pos of row start in image
			   x_size);		      	      // length of row
    }

	return statusCode;
}

template <class T> 
int KScData2d<T>::SetSection(T *section, int x_i, int y_j, int x_size, int y_size)
{
	if (x_i < 0 || x_i > dx || y_j < 0 || y_j > dy)
		return statusCode = OUT_OF_RANGE;

	// fill in this memory, from bottom to top.  memory should contain
	// bottom row, then second-bottom row, ..., top row.
	for (register int row_idx = 0 ; row_idx < y_size ; row_idx++)
    {
		SetRow(section + row_idx * x_size, // start of row in memory
			   row_idx + y_j,				   // y pos of row start in image
			   x_i,						   // x pos of row start in image
			   x_size);		      	       // length of row
    }

	return statusCode = NO_ERROR;
}

template <class T> 
KScData2d<T> &KScData2d<T>::operator=(KScData2d<T> &from_d2p)
{
	if (this != &from_d2p)
    {
		int x_size = dx, y_size = dy;
		
		if (x_size != from_d2p.dx || y_size != from_d2p.dy)
			statusCode = NO_SIZE_CONFORMANCE;
	    else
		{
			if (from_d2p.GetName() != NULL)
				SetName(from_d2p.GetName());
			else 
				ClearName();

			// copy actual data from one rep to the other
			T* row = new T[x_size];

			for (register int j = 0 ; j < y_size ; j++)
			{
				from_d2p.GetRow(row, j, 0, x_size);
				SetRow(row, j, 0, x_size);
			}
			delete []row;
		}
    }

	return *this;
}

typedef KScData2d<char>				KScData2dInt8;
typedef KScData2d<unsigned char>	KScData2dUint8;
typedef KScData2d<short>			KScData2dInt16;
typedef KScData2d<unsigned short>	KScData2dUint16;
typedef KScData2d<int>				KScData2dInt32;
typedef KScData2d<unsigned int>		KScData2dUint32;
typedef KScData2d<float>			KScData2dFloat;
typedef KScData2d<double>			KScData2dDouble;
typedef KScData2d<long double>		KScData2dLdouble;
typedef KScData2d<KSdRgb>			KScData2dRgb;
typedef KScData2d<KSdComplex>		KScData2dComplex;

#endif
