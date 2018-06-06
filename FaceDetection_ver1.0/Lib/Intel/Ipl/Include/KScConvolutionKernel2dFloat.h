#ifndef __KSC_CONVOLUTION_KERNEL_2D_FLOAT_H__
#define __KSC_CONVOLUTION_KERNEL_2D_FLOAT_H__

#include "KScData2d.h"
#include "KScConvolutionKernel.h"

class KS_CLASS KScConvolutionKernel2dFloat : public KScConvolutionKernel
{

// attribute
public:
	KScData2dFloat *pRealData; // original image pointer
	KSdFloat       *pData;	   // access image pointer

public:

// methods
public:

	KScConvolutionKernel2dFloat(void);
	KScConvolutionKernel2dFloat(char *name);
	KScConvolutionKernel2dFloat(char *name, int nX, int nY);
	KScConvolutionKernel2dFloat(char *name, int nX, int nY, int ax, int ay);
	KScConvolutionKernel2dFloat(char *name, int nX, int nY, int ax, int ay, int r);
	virtual	~KScConvolutionKernel2dFloat(void);

	int  Alloc(int nX, int nY);
	void Free(void);

	KSdFloat* GetBuffer(void);
};

#endif
