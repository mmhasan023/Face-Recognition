#ifndef __KSC_SEQUENCE_VIDEO_H__
#define __KSC_SEQUENCE_VIDEO_H__

#include "KScSequenceBase.h"

// Seek method Constants
#ifndef SEEK_SET

	#define SEEK_SET 0
	#define SEEK_CUR 1
	#define SEEK_END 2

#endif // SEEK_SET

class KScSequenceBlockImage;

class KS_CLASS KScSequenceVideo : public KScSequenceBase 
{

// attribute
public:

	int           width, height;
	int           bpp;

	int           rate;                  // frame / second

	unsigned long keyFrameNumber;        // the number of total key frame
	unsigned long duration;              // the time between keyframes

	int           start, current, end;   // start, current and end of current stream

	// all
	void          *pData;                // real stream or frame buffer
	                                     // BITMAPINFO + Bitstream

	// partial
	int                   blockNumber;   // number of block in stream
	KScSequenceBlockImage **pImageBlock; // several block pointer in stream

// methods
public:

	KScSequenceVideo(void);
	KScSequenceVideo(char *name);

	virtual	~KScSequenceVideo(void);

	KScSequenceVideo& operator=(KScSequenceVideo& source);

	// Get/Set width, height, bpp
	int  GetWidth(void);
	void SetWidth(int value);

	int  GetHeight(void);
	void SetHeight(int value);

	int  GetBpp(void);
	void SetBpp(int value);

	// Get/Set rate
	int  GetRate(void);
	void SetRate(int value);

	// Get/Set total keyframe number
	unsigned long GetKeyFrameNumber(void);
	void		  SetKeyFrameNumber(unsigned long number);

	// Get/Set duration between keyframes
	unsigned long GetDuration(void);
	void          SetDuration(unsigned long dur);

	// Get/Set scale type
	int  GetScaleType(void);
	void SetScaleType(int type);

	// Get/Put Frame
	void* GetFrame(unsigned long lTime);
	int /*BOOL*/ PutFrame (unsigned long lTime, void *pBuffer);

	// Get/Put KeyFrame
	// Get or put a frame that is most close to specific time.
	void* GetKeyFrame(unsigned long lTime);
	int /*BOOL*/ PutKeyFrame (unsigned long lTime, void *pBuffer);

	// Get/Put Block
	void* GetBlock(int index, unsigned long start, unsigned long end);
	int /*BOOL*/ PutBlock (int index, unsigned long start, unsigned long end, void *pBuffer);

/*
	// Convert
	
	// Time

	// 

	// File
	int /*BOOL* / Open(FILE *fp);
	void Close(void);
	int /*BOOL* / Save(FILE *fp);
	int /*BOOL* / Save(FILE *fp, unsigned long lStartTime, unsigned lEndTime);

	// Device
	int /*BOOL* / OpenDevice(...);
	void CloseDevice(void);

	// Play
	int /*BOOL* / Play (void);
	int /*BOOL* / Stop (void);
	int /*BOOL* / Pause(void);

	// Seek
	int /*BOOL* / Seek(unsigned long lTime); // lTime is Seek method constants or time.
*/

};

#endif
