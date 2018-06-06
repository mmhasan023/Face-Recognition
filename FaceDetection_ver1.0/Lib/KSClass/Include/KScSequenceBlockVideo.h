 #ifndef __KSC_SEQUENCE_BLOCK_VIDEO_H__
#define __KSC_SEQUENCE_BLOCK_VIDEO_H__

#include "KScSequenceBlock.h"

class KS_CLASS KScSequenceBlockVideo : public KScSequenceBlock
{

// attribute
public:

	int           width, height;
	int           bpp;

	unsigned long frameNumber;      // the number of total key frame
	unsigned long duration;         // the time between frames

// methods
public:

	KScSequenceBlockVideo(void);
	KScSequenceBlockVideo(char *name);

	virtual	~KScSequenceBlockVideo(void);

	KScSequenceBlockVideo& operator=(KScSequenceBlockVideo& source);

	// Get/Set total frame number
	unsigned long GetFrameNumber(void);
	void		  SetFrameNumber(unsigned long number);

	// Get/Set duration between keyframes
	unsigned long GetDuration(void);
	void          SetDuration(unsigned long dur);

	// Get/Set Frame
	void* GetFrame(unsigned int index);
    int /*BOOL*/ PutFrame(unsigned int index, void *pBuffer);
};

#endif
