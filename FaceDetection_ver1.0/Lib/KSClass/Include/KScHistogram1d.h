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
// 2002.05.20. - Younghyun Ha
	int    highValue;    // ������׷��� ������ ��ġ�� �ε��� ��
						 // ���� 0-255�� �̿��Ѵٰ� �ϸ� 255�� ��Ÿ����.
						 // 200-512�̸� 512�� ��Ÿ����.
// 2002.05.20. - Younghyun Ha - End

// methods
public:

	KScHistogram1d(void); 
	KScHistogram1d(char *name); 
// 2002.05.20. - Younghyun Ha
//	KScHistogram1d(char *name, int lowValue, int bucketNumber, double bucketWidth);
	KScHistogram1d(char *name, int lowValue, int highValue, int bucketNumber, double bucketWidth);
// 2002.05.20. - Younghyun Ha - End
	KScHistogram1d(char *name, int bucketNumber, double bucketWidth); 
	KScHistogram1d(char *name, int bucketNumber); 
	virtual	~KScHistogram1d(void);

// 2002.05.20. - Younghyun Ha - End
//	int  Alloc(int lowValue, int bucketNumber, double bucketWidth); 
	int  Alloc(int lowValue, int highValue, int bucketNumber, double bucketWidth); 
// 2002.05.20. - Younghyun Ha - End
	int  Alloc(int bucketNumber, double bucketWidth); 
	int  Alloc(int bucketNumber); 
	void Free(void);

	void InitTo(int value=0);

	long* GetBuffer(void);       // bucket ������
	long* GetBucketBuffer(void); // GetBuffer()�� ����
	
	double GetBucketWidth (void);
	long   GetBucketCount (int bucketNumer);
	long   GetIndexCount  (double index);
	int    GetBucketNumber(void);
	int    GetLowValue    (void);
// 2002.05.20. - Younghyun Ha
	int    GetHighValue   (void);
// 2002.05.20. - Younghyun Ha - End

	double Mean          (void);
	double Variance      (void);
	int    FindPeakBucket(void);

	// ������ bucket�� �߰� ��ġ�� ����� �˷����� �� ��� ...
	double GetBucketMiddle(int bucketIndex);

	// operator overloading������ ���.
	void SetLowValue   (int value);
// 2002.05.20. - Younghyun Ha
	void SetHighValue   (int value);
// 2002.05.20. - Younghyun Ha - End
	void SetBucketWidth(double width);

	int  Accumulate         (double index);
	void IncreaseBucketCount(int num);

	int CalcScalarImage(KScScalarImage2dUint8 *src);
	int CalcScalarImage(KScData2dUint8 *src);

	KScHistogram1d& operator=(KScHistogram1d& histogram);
};

#endif
