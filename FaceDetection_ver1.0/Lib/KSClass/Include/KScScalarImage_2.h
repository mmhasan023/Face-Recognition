#ifndef __KSC_SCALARIMAGE_H__
#define __KSC_SCALARIMAGE_H__

#include "KScSimpleImage.h"
#include "KScData.h"

class KS_CLASS KScScalarImage : public KScSimpleImage 
{

// attribute
public:

// methods
public:

	KScScalarImage(void);
	KScScalarImage(char *szName);
	virtual	~KScScalarImage(void);

	virtual void GetPixel(KSdUint8 &pixel, int* index);
	virtual void GetPixel(KSdInt16 &pixel, int* index);
	virtual void GetPixel(KSdInt32 &pixel, int* index);
	virtual void GetPixel(KSdFloat &pixel, int* index);
	virtual void GetPixel(KSdDouble &pixel, int* index);

	virtual void SetPixel(KSdUint8 &pixel, int* index);
	virtual void SetPixel(KSdInt16 &pixel, int* index);
	virtual void SetPixel(KSdInt32 &pixel, int* index);
	virtual void SetPixel(KSdFloat &pixel, int* index);
	virtual void SetPixel(KSdDouble &pixel, int* index);

	virtual void InitTo(KSdUint8 pixel=0);
	virtual void InitTo(KSdInt16 pixel=0);
	virtual void InitTo(KSdInt32 pixel=0);
	virtual void InitTo(KSdFloat pixel=0.0f);
	virtual void InitTo(KSdDouble pixel=0.0);

	KScScalarImage& operator=(KScScalarImage& src);
};

#endif
