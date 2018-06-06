#ifndef __KSC_CONVOLUTION_KERNEL_2D_INT32_H__
#define __KSC_CONVOLUTION_KERNEL_2D_INT32_H__

#include "KScData2d.h"
#include "KScConvolutionKernel.h"

class KS_CLASS KScConvolutionKernel2dInt32 : public KScConvolutionKernel
{

// attribute
public:
	KScData2dInt32 *pRealData;	// original image pointer
	KSdInt32       *pData;		// access image pointer

public:

// methods
public:

	KScConvolutionKernel2dInt32(void);
	KScConvolutionKernel2dInt32(char *name);
	KScConvolutionKernel2dInt32(char *name, int nX, int nY);
	KScConvolutionKernel2dInt32(char *name, int nX, int nY, int ax, int ay);
	KScConvolutionKernel2dInt32(char *name, int nX, int nY, int ax, int ay, int r);
	virtual	~KScConvolutionKernel2dInt32(void);

	virtual int  Alloc(int nX, int nY);
	virtual void Free(void);

	KSdInt32* GetBuffer(void);
};

#endif
