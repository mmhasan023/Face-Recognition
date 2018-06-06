#ifndef __KSC_COLORIMAGE_H__
#define __KSC_COLORIMAGE_H__

#include "KScSimpleImage.h"

class KS_CLASS KScColorImage : public KScSimpleImage 
{

// memeber variable
public :

// member function
public :

	KScColorImage();
	KScColorImage(char *szName);

	virtual	~KScColorImage();

protected :

	KScColorImage& operator=(KScColorImage& src);
};

#endif