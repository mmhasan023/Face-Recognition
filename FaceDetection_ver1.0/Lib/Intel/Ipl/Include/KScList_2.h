#ifndef __KSC_LIST_H__
#define __KSC_LIST_H__

// 이 MyList를 구현하기 위해 참조함 MFC의 파일들
// \MSDEV\VC\mfc\inclue\ afxcoll.h
// \MSDEV\VC\mfc\inclue\ afxcoll.ini
// \MSDEV\VC\mfc\inclue\ afxplex.h
// \MSDEV\VC\mfc\inclue\ afxtempl.h
// \MSDEV\VC\mfc\src\ List_p.cpp
// \MSDEV\VC\mfc\inclue\ Plex.cpp

// #include "stdafx.h" - stdafx.h를 포함하면 MFC에 종속되게 된다.
// 아래의 Basic types은 <afx.h> 에 정의 되어 있다.
// PtrList는 MFC와 무관하게 구성되므로 여기서 이용되는
// H_POSITION에 대한 정의 부분을 가져온 것이다.
// 원래의 소스는 아래와 같으며 기존의 MFC화일과의 충돌을 막기 위해 H_를 추가하였다.
//
// struct __POSITION { };
// typedef __POSITION* POSITION;
//
/////////////////////////////////////////////////////////////////////////////
// Basic types
// abstract iteration position
struct __H_POSITION { };
typedef __H_POSITION* H_POSITION;
// Basic types 끝
/////////////////////////////////////////////////////////////////////////////

struct CMyPlex     // warning variable length structure
{
	CMyPlex* pNext;

	// BYTE data[maxNum*elementSize];

	void* data() { return this+1; }

	static CMyPlex* __stdcall Create(CMyPlex*& head, unsigned int nMax, unsigned int cbElement);
			// like 'calloc' but no zero fill
			// may throw memory exceptions

	void FreeDataChain();       // free this one and links
};

#include "KScObject.h"

/////////////////////////////////////////////////////////////////////////////
class KS_CLASS KScList// : public CObject
{

//	DECLARE_DYNAMIC(KScList)

public:

struct CNode
{
	CNode* pNext;
	CNode* pPrev;
	void*  data;
};

// Construction
	KScList(int nBlockSize = 10);

// Attributes (head and tail)
	// count of elements
	int GetCount() const;
	int IsEmpty() const;

	// peek at head or tail
	void*& GetHead();
	void* GetHead() const;
	void*& GetTail();
	void* GetTail() const;

// Operations
	// get head or tail (and remove it) - don't call on empty list!
	void* RemoveHead();
	void* RemoveTail();

	// add before head or after tail
	H_POSITION AddHead(void* newElement);
	H_POSITION AddTail(void* newElement);

	// add another list of elements before head or after tail
	void AddHead(KScList* pNewList);
	void AddTail(KScList* pNewList);

	// remove all elements
	void RemoveAll();

	// iteration
	H_POSITION GetHeadPosition() const;
	H_POSITION GetTailPosition() const;
	void*& GetNext(H_POSITION& rPosition); // return *Position++
	void* GetNext(H_POSITION& rPosition) const; // return *Position++
	void*& GetPrev(H_POSITION& rPosition); // return *Position--
	void* GetPrev(H_POSITION& rPosition) const; // return *Position--

	// getting/modifying an element at a given position
	void*& GetAt(H_POSITION position);
	void* GetAt(H_POSITION position) const;
	void SetAt(H_POSITION pos, void* newElement);
	void RemoveAt(H_POSITION position);

	// inserting before or after a given position
	H_POSITION InsertBefore(H_POSITION position, void* newElement);
	H_POSITION InsertAfter(H_POSITION position, void* newElement);

	// helper functions (note: O(n) speed)
	H_POSITION Find(void* searchValue, H_POSITION startAfter = (H_POSITION)0) const;
						// defaults to starting at the HEAD
						// return NULL if not found
	H_POSITION FindIndex(int nIndex) const;
						// get the 'nIndex'th element (may return NULL)

// Implementation
protected:
	CNode* m_pNodeHead;
	CNode* m_pNodeTail;
	int m_nCount;
	CNode* m_pNodeFree;
	struct CMyPlex* m_pBlocks;
	int m_nBlockSize;

	CNode* NewNode(CNode*, CNode*);
	void FreeNode(CNode*);

public:
	virtual	~KScList();

	// local typedefs for class templates
	typedef void* BASE_TYPE;
	typedef void* BASE_ARG_TYPE;
};

#endif //__KSC_LIST_H__

/////////////////////////////////////////////////////////////////////////////
