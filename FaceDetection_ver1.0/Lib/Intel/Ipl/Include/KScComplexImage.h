#ifndef __KSC_COMPLEXIMAGE_H__
#define __KSC_COMPLEXIMAGE_H__

#include "KScSimpleImage.h"

#define COMPLEX_PLANE_NUM		2

class KS_CLASS KScComplexImage : public KScSimpleImage 
{

// memeber variable
public :

// member function
public :

	KScComplexImage();
	KScComplexImage(char *szName);

	virtual	~KScComplexImage();

protected :

	KScComplexImage& operator=(KScComplexImage& src);
};

#endif
