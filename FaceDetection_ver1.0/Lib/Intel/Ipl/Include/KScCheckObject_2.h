#ifndef __KSC_CHECK_OBJECT_H__
#define __KSC_CHECK_OBJECT_H__

#include <string.h>

#ifdef KS_CLASS_EXPORTS
    #define KS_CLASS __declspec(dllexport)
#else
    #define KS_CLASS __declspec(dllimport)
#endif

// �� object���� Ŭ���� Ÿ�� �˻縦 ���� ������� Ŭ���� ...
class KS_CLASS KScCheckObject
{
private:
	
	void *p;		// ��� ���踦 ��Ÿ���� �������� ��ġ�� ����Ų��.
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
