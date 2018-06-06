#ifndef __KSC_CONVOLUTION_KERNEL_H__
#define __KSC_CONVOLUTION_KERNEL_H__

#include "KScSimpleImage.h"

class KS_CLASS KScConvolutionKernel : public KScSimpleImage
{

// attribute
public:
	int nCols;
	int nRows;
	int anchorX;
	int anchorY;

	int nShiftR;
// methods
public:

	KScConvolutionKernel();
	KScConvolutionKernel(char *szName);

	virtual	~KScConvolutionKernel();

	void SetColumn(int col);
	void SetRow   (int row);
	int  GetColumn(void);
	int  GetRow   (void);

	void SetAnchorX(int x);
	void SetAnchorY(int y);
	int  GetAnchorX(void);
	int  GetAnchorY(void);

	void SetShiftRight(int value);
	int  GetShiftRight(void);
};

#endif
