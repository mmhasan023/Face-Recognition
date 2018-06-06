#ifndef __KSGENERICIMAGE_H__
#define __KSGENERICIMAGE_H__

#include "KScObject.h"

#define DEFAULT_PLANE		1
#define DEFAULT_DIMENSION	2

class KS_CLASS KScGenericImage : public KScObject 
{
// attribute
public :

	int dx, dy, dz;             // 4's size
	int realDx, realDy, realDz; // origianl size
	
	// 처리 중 크기가 변할 경우에 이전 크기 저장
	int old_dx, old_dy, old_dz;

// 2001.10.23. - Younghyun Ha
//	int bpp;    // bytes per pixel
	int bpp;    // bits per pixel
// 2001.10.23. - Younghyun Ha - End

	int dim;    // dimension
	int plane;	// image plane : scalar = 1, rgb = 3, cmyk = 4

// methods
public:

	KScGenericImage(void);
	KScGenericImage(char *name);

	virtual	~KScGenericImage(void);

	virtual int GetXSize(void);
	virtual int GetYSize(void);
	virtual int GetZSize(void);

	virtual int GetRealXSize(void);
	virtual int GetRealYSize(void);
	virtual int GetRealZSize(void);

	virtual int GetOldXSize(void);
	virtual int GetOldYSize(void);
	virtual int GetOldZSize(void);

	int         GetBPP(void);
	int         GetDimension(void);
	virtual int GetPlaneNum(void);

protected:

	virtual void SetXSize(int x);
	virtual void SetYSize(int y);
	virtual void SetZSize(int z);

	virtual void SetRealXSize(int x);
	virtual void SetRealYSize(int y);
	virtual void SetRealZSize(int z);

	virtual void SetOldXSize(int x);
	virtual void SetOldYSize(int y);
	virtual void SetOldZSize(int z);

	void SetDimension(int d);
	void SetPlaneNum(int p);

	virtual void SetBPP(int b);
};

#endif
