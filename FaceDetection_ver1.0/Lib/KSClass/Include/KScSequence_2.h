#ifndef __KSC_SEQUENCE_H__
#define __KSC_SEQUENCE_H__

#include "KScObject.h"
#include "KScList.h"

// Seek method Constants
#ifndef SEEK_SET

	#define SEEK_SET 0
	#define SEEK_CUR 1
	#define SEEK_END 2

#endif // SEEK_SET

class KS_CLASS KScSequence : public KScObject 
{

// attribute
public:

	KScList      stream;              // store some streams

	int          start, current, end; // start, current and end in current stream

	char         *filename;           // original filename

	void         *avi;                // PAVIFILE

	void         *vidcap;             // Video Capture Device

// methods
public:

	KScSequence(void);
	KScSequence(char *name);

	virtual	~KScSequence(void);

	KScSequence& operator=(KScSequence& source);

	// Get number
	unsigned int GetStreamNumber(void);

	unsigned int GetVideoStreamNumber(void);

	unsigned int GetAudioStreamNumber(void);

	unsigned int GetTextStreamNumber(void);

	unsigned int GetMidiStreamNumber(void);

	// Get stream
	void* GetStream(H_POSITION pos);
	void* GetStream(int        index);

	// Get/Set the original filename
	char*        GetFilename(void);
	int/*BOOL*/  SetFilename(char *filename);

	// allocate / deallocate
	void FreeAvi     (void);
	void FreeFilename(void);

	// Get PAVIFILE
	void* GetAvi   (void);

	// Get PAVIFILE / VIDCAP
	int/*BOOL*/ AllocForVidCap(long size);
	void*       GetVidCap     (void);

	// Seek
	virtual int/*BOOL*/ Seek(unsigned long index=SEEK_CUR); // Seek method constants or time.

	// Convert
	
	// Time

/* 아래는 대부분 OS Dependent 한 함수들

	// File
	virtual BOOL Open(FILE *fp);
	virtual 	void Close(void);
	virtual 	BOOL Save(FILE *fp);
	virtual 	BOOL Save(FILE *fp, unsigned long start, unsigned end);

	// Device
	virtual BOOL OpenDevice(...);
	virtual void CloseDevice(void);

	// Play
	virtual BOOL Play (void);
	virtual BOOL Stop (void);
	virtual BOOL Pause(void);
*/
};

#endif
