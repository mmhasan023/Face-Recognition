#ifndef __KSC_CHECK_OBJECT_H__
#define __KSC_CHECK_OBJECT_H__

#include <string.h>

#ifdef KS_CLASS_EXPORTS
    #define KS_CLASS __declspec(dllexport)
#else
    #define KS_CLASS __declspec(dllimport)
#endif

// 각 object들을 클래스 타입 검사를 위해 만들어진 클래스 ...
class KS_CLASS KScCheckObject
{
private:
	
	void *p;		// 상속 관계를 나타내는 포인터의 위치를 가리킨다.
	int  checkId;
	char *className;

public:

	KScCheckObject(void);
	virtual	~KScCheckObject(void);

	int   GetId  (void);
	char *GetName(void);
	void SetName (char *name);
};
#endif
