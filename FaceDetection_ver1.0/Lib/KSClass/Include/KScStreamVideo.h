#ifndef __KSC_STREAM_VIDEO_H__
#define __KSC_STREAM_VIDEO_H__

#include "KScStream.h"

class KS_CLASS KScStreamVideo : public KScStream 
{

// attribute
public:

	void *frameObject;          // PGETFRAME  - GetFrame object : only video stream

// methods
public:

	KScStreamVideo(void);
	KScStreamVideo(char *name);

	virtual	~KScStreamVideo(void);

	KScStreamVideo& operator=(KScStreamVideo& source);

	// Get/Set GetFrame
	void* GetFrameObject(void);
	void  SetFrameObject(void *stream);

};

#endif
