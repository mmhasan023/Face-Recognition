#ifndef __KSC_STREAM_H__
#define __KSC_STREAM_H__

#include "KScObject.h"
#include "KScList.h"

#ifdef KS_CLASS_PRJ

	// Seek method Constants
	#define SEEK_SET 0
	#define SEEK_CUR 1
	#define SEEK_END 2

#endif

class KS_CLASS KScStream : public KScObject 
{

// attribute
public:

	int  start, current, end; // In sample, start, current and end in current stream

	void *stream;             // PAVISTREAM - store a stream

	void *editableStream;     // PAVISTREAM - editalbe stream

	void *compressedStream;   // PAVISTREAM - compressed stream maked AVIMakeCompressedStream()

	void *avis;               // AVISTREAMINFO

	void *aviCompressOption;  // AVICOMPRESSOPTIONS

// methods
public:

	KScStream(void);
	KScStream(char *name);

	virtual	~KScStream(void);

	KScStream& operator=(KScStream& source);

	// Get/Set stream
	void* GetStream(void);
	void  SetStream(void *stream);

	void* GetEditableStream(void);
	void  SetEditableStream(void *editableStream);

	void* GetCompressedStream(void);
	void  SetCompressedStream(void *compressedStream);

	// Get/Set Stream information
	void* /* AVISTREAMINFO* */ GetAVIStreamInfo(void);
	// [long size] is the size of [void*]
	int/*BOOL*/                SetAVIStreamInfo(void* /* AVISTREAMINFO */ avis, long size);

	// Get/Set Compression option
	void* /* AVICOMPRESSOPTIONS* */ GetAVICompressOption(void);
	// [long size] is the size of [void*]
	int/*BOOL*/                SetAVICompressOption(void* /* AVICOMPRESSOPTIONS* */ aviCompressOption, long size);

	// Get/Set Stream type
	unsigned long/*DWORD*/ GetStreamType(void);
	// [long size] is the size of [void*]
	void                   SetStreamType(unsigned long/*DWORD*/ type, long size);

	// Get/Set Stream type
	unsigned long/*DWORD*/ GetCODEC(void);
	// [long size] is the size of [void*]
	void                   SetCODEC(unsigned long/*DWORD*/ codec, long size);

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

#undef RECT

#endif
