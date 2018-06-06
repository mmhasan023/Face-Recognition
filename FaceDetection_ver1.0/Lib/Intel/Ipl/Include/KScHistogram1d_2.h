#ifndef __KSC_HISTOGRAM_1D_H__
#define __KSC_HISTOGRAM_1D_H__

#include "KScHistogram.h"
#include "KScData2d.h"
#include "KScScalarImage2dUint8.h"

class KS_CLASS KScHistogram1d : public KScHistogram
{

// attribute
public:
	int    bucketNumber; // ��ü ������ bucket�� ���� �ǹ��Ѵ�.
	double bucketWidth;	 // ��ü histogram�߿��� �׷����� �׷��� ��Ÿ����.
						 // ������ ������׷��� 1.0�� ��Ÿ����.
	long   *bucket;      // bucket�� �����ϱ� ���� �迭.
	int    lowValue;     // ������׷��� ���۵Ǵ� ��ġ�� �ε��� ��
						 // ���� 0-255�� �̿��Ѵٰ� �ϸ� 0�� ��Ÿ����.
						 // 200-512�̸� 200�� ��Ÿ����.

// methods
public:

	KScHistogram1d(void); 
	KScHistogram1d(char *name); 
	KScHistogram1d(char *name, int lValue, int bNum, double bWidth); 
	KScHistogram1d(char *name, int bNum, double bWidth); 
	KScHistogram1d(char *name, int bNum); 
	virtual	~KScHistogram1d(void);

	int  Alloc(int lValue, int numOfBucket, double widthBucket); 
	int  Alloc(int numOfBucket, double widthBucket); 
	int  Alloc(int numOfBucket); 
	void Free(void);

	void InitTo(int value=0);

	long* GetBuffer(void);       // bucket ������
	long* GetBucketBuffer(void); // GetBuffer()�� ����
	
	double GetBucketWidth (void);
	long   GetBucketCount (int bucketNum);
	long   GetIndexCount  (double index);
	int    GetBucketNumber(void);
	int    GetLowValue    (void);

	double Mean          (void);
	double Variance      (void);
	int    FindPeakBucket(void);

	// ������ bucket�� �߰� ��ġ�� ����� �˷����� �� ��� ...
	double GetBucketMiddle(int bucketIndex);

	// operator overloading������ ���.
	void SetLowValue   (int lValue);
	void SetBucketWidth(double width);

	int  Accumulate         (double index);
	void IncreaseBucketCount(int num);

	KScHistogram1d& operator=(KScHistogram1d&  rhs);

	int CalcScalarImage(KScScalarImage2dUint8 *src);
	int CalcScalarImage(KScData2dUint8 *src);
};

#endif
