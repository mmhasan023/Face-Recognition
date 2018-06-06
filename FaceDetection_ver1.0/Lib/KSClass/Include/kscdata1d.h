#ifndef __KSC_DATA1D_H__
#define __KSC_DATA1D_H__

#include "KScObject.h"
#include "KScData.h"
#include "KScData1d.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

template <class T>
class  KScData1d : public KScData
{

// attribute
public:
	
	T *pBuffer;

// methods
public:

	KScData1d(void) 
	{
		id  = KS_DATA_1D + sizeof(T);
		dy  = dz = 1;
		dim = 1;
		bpu = sizeof(T);

		pBuffer = NULL;
	}

	KScData1d(char *szName) : KScData(szName)	//19991223 ªÛ«Â ∫Ø∞Ê
	{
		id  = KS_DATA_1D + sizeof(T);
		dy  = dz = 1;
		dim = 1;
		bpu = sizeof(T);

//		SetName(name);

		pBuffer = NULL;
	}

	KScData1d(char* name, int size);
	KScData1d(int size);

	virtual	~KScData1d(void);

	int  Alloc  (int size);
	void Free   (void);
	int  Realloc(int size);

	int  InitTo (int value=0);

	void SetPixel(T value, int x);
	T    GetPixel(int x);

	int SetSection(T *row, int x, int len);
	int GetSection(T *row, int x, int len);
	T*  GetSection(int x, int len);

	int GetXSize(void)   { return dx; }
	T*  GetBuffer(void)  { return pBuffer; }

	KScData1d<T> &operator=(KScData1d<T> &p);
};


template <class T> 
KScData1d<T>::KScData1d(char *name, int size) : KScData(name)
{
	id  = KS_DATA_1D + sizeof(T);
	dx  = size;
	dy  = dz = 1;
	dim = 1;
	bpu = sizeof(T);

	SetName(name);

	//pBuffer = (T*)malloc(sizeof(T) * dx);
	pBuffer = new T [sizeof(T) * dx];
	if (pBuffer == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return;
	}
	
	if (InitTo(0) != NO_ERROR)
		return;

	statusCode = NO_ERROR;
}

template <class T> 
KScData1d<T>::KScData1d(int size)
{
	id  = KS_DATA_1D + sizeof(T);
	dx  = size;
	dy  = dz = 1;
	dim = 1;
	bpu = sizeof(T);

	//pBuffer = (T*)malloc(sizeof(T) * dx);
	pBuffer = new T [sizeof(T) * dx];
	if (pBUffer == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return;
	}
	
	if (InitTo(0) != NO_ERROR)
		return;

	statusCode=NO_ERROR;
}

template <class T> 
KScData1d<T>::~KScData1d(void)
{
	Free();
}

template <class T> 
int KScData1d<T>::Alloc(int size)
{
	if (!size)
		return statusCode = NO_ALLOC_MEMORY;

	if (GetBuffer() != NULL)
		return statusCode = ALREADY_ALLOC_MEMORY;
	else
	{
		//pBuffer = (T*)malloc(sizeof(T) * size);
		pBuffer = new T [sizeof(T) * size];
		if (!pBuffer)
			return statusCode = FAIL_ALLOC_MEMORY;
		else
		{
			dx  = size;
			bpu = sizeof(T);
			return InitTo();
		}
	}
}

template <class T> 
void KScData1d<T>::Free()
{
	if (GetXSize() != 0 && GetBuffer() != NULL)
		delete pBuffer;

	pBuffer = NULL;

	ResetClass();
}

template <class T> 
int KScData1d<T>::Realloc(int size)
{
	Free();
	return Alloc(size);
}

template <class T> 
int KScData1d<T>::InitTo(int value)
{
	if (GetBuffer() == NULL)
		return statusCode = NO_ALLOC_MEMORY;

	for (register int i = 0 ; i < dx ; i++)
		pBuffer[i] = (T)value;

	return statusCode = NO_ERROR;
}

template <class T> 
T KScData1d<T>::GetPixel(int x)
{
	return (GetBuffer() != NULL) ? pBuffer[x] : 0x00;
}

template <class T> 
void KScData1d<T>::SetPixel(T value, int x)
{
	if (GetBuffer() != NULL)
		pBuffer[x] = value;
}

template <class T> 
T* KScData1d<T>::GetSection(int x, int len)
{
	if (x < 0 || x > dx)
	{
		statusCode = OUT_OF_RANGE;
		return NULL;
	}

	//T*  row = (T*)malloc(len * sizeof(T));
	T *row = new T [sizeof(T) * len];
	if (row == NULL)
	{
		statusCode = FAIL_ALLOC_MEMORY;	
		return NULL;
	}

	if (GetBuffer() != NULL)
	{
		if (x + len > dx)
		{
			int bound_len = dx - x;
			memcpy(row, pBuffer + x, sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T) * (len - bound_len));
		}
		else
			memcpy(row, pBuffer + x, sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return row;
}

template <class T> 
int KScData1d<T>::GetSection(T * row, int x, int len)
{
	if (x < 0 || x > dx)
		return statusCode = OUT_OF_RANGE;

	if (GetBuffer() != NULL)
	{
		if (x + len > dx)
		{
			int bound_len = dx - x;
			memcpy(row, pBuffer + x, sizeof(T) * bound_len);
			memset(row + bound_len, 0, sizeof(T) * (len - bound_len));
		}
		else
			memcpy(row, pBuffer + x, sizeof(T) * len);

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return statusCode;
}

template <class T> 
int KScData1d<T>::SetSection(T * row, int x, int len)
{
	if (x < 0 || x > dx)
		return statusCode = OUT_OF_RANGE;

	if (GetBuffer() != NULL)
	{
		memcpy(pBuffer + x, row, sizeof(T) * ((x + len > dx) ? dx - x : len));

		statusCode = NO_ERROR;
	}
	else
		statusCode = NO_ALLOC_MEMORY;

	return statusCode;
}

template <class T> 
KScData1d<T> &KScData1d<T>::operator=(KScData1d<T> &p)
{
	if (this == &p)
		return *this;
    
	if (dx != p.dx)
	{
		Free();
		statusCode = Alloc(p.dx);
		if (statusCode != NO_ERROR)
			return *this;
	}

	if (!GetName() && p.GetName())
		SetName(p.GetName());

	// copy actual data from one rep to the other
	T* row = new T[p.dx];
	p.GetSection(row, 0, p.dx);
	SetSection  (row, 0, p.dx);
	delete row;
    
	return *this;
}

typedef KScData1d<char> KScData1dInt8;
typedef KScData1d<unsigned char> KScData1dUint8;
typedef KScData1d<short int> KScData1dInt16;
typedef KScData1d<unsigned short int> KScData1dUint16;
typedef KScData1d<int> KScData1dInt32;
typedef KScData1d<unsigned int> KScData1dUint32;
typedef KScData1d<float> KScData1dFloat;
typedef KScData1d<double> KScData1dDouble;
typedef KScData1d<long double> KScData1dLdouble;

#endif
