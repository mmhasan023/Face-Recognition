#ifndef __KSC_CONVOLUTION_KERNEL_2D_INT8_H__
#define __KSC_CONVOLUTION_KERNEL_2D_INT8_H__

#include "KScData2d.h"
#include "KScConvolutionKernel.h"

class KS_CLASS KScConvolutionKernel2dInt8 : public KScConvolutionKernel
{

// attribute
public:
	KScData2dInt8 *pRealData; // original image pointer
	KSdInt8       *pData;     // access image pointer

public:
								   
// methods
public:

	KScConvolutionKernel2dInt8(void);
	KScConvolutionKernel2dInt8(char *name);
	KScConvolutionKernel2dInt8(char *name, int nX, int nY);
	KScConvolutionKernel2dInt8(char *name, int nX, int nY, int ax, int ay);
	KScConvolutionKernel2dInt8(char *name, int nX, int nY, int ax, int ay, int r);
	virtual	~KScConvolutionKernel2dInt8(void);

	int  Alloc(int nX, int nY);
	void Free(void);

	KSdInt8* GetBuffer(void);
};

#endif
