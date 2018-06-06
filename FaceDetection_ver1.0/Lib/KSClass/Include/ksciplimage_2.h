// KScIplImage.h: interface for the KScIplImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KSCIPLIMAGE_H__9169E8A8_FA19_4BF5_AD79_9680B6053642__INCLUDED_)
#define AFX_KSCIPLIMAGE_H__9169E8A8_FA19_4BF5_AD79_9680B6053642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KScObject.h"

#ifdef KS_CLASS_EXPORTS
#include "IplType.h"
#else
#include "Ipl.h"
#endif

class KS_CLASS KScIplImage : public KScObject  
{
public:
	KScIplImage();
	KScIplImage(char *szName);
	KScIplImage(char *szName, int dx, int dy);

	virtual ~KScIplImage();

	IplImage image;
};

#endif // !defined(AFX_KSCIPLIMAGE_H__9169E8A8_FA19_4BF5_AD79_9680B6053642__INCLUDED_)
