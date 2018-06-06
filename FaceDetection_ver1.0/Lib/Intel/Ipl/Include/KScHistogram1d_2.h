#ifndef __KSC_HISTOGRAM_1D_H__
#define __KSC_HISTOGRAM_1D_H__

#include "KScHistogram.h"
#include "KScData2d.h"
#include "KScScalarImage2dUint8.h"

class KS_CLASS KScHistogram1d : public KScHistogram
{

// attribute
public:
	int    bucketNumber; // 전체 저장할 bucket의 수를 의미한다.
	double bucketWidth;	 // 전체 histogram중에서 그룹지은 그룹을 나타낸다.
						 // 보통의 히스토그램은 1.0을 나타낸다.
	long   *bucket;      // bucket를 저장하기 위한 배열.
	int    lowValue;     // 히스토그램이 시작되는 위치의 인덱스 값
						 // 보통 0-255를 이용한다고 하면 0을 나타낸다.
						 // 200-512이면 200을 나타낸다.

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

	long* GetBuffer(void);       // bucket 포인터
	long* GetBucketBuffer(void); // GetBuffer()와 동일
	
	double GetBucketWidth (void);
	long   GetBucketCount (int bucketNum);
	long   GetIndexCount  (double index);
	int    GetBucketNumber(void);
	int    GetLowValue    (void);

	double Mean          (void);
	double Variance      (void);
	int    FindPeakBucket(void);

	// 지정된 bucket의 중간 위치가 어딘지 알려고할 때 사용 ...
	double GetBucketMiddle(int bucketIndex);

	// operator overloading에서만 사용.
	void SetLowValue   (int lValue);
	void SetBucketWidth(double width);

	int  Accumulate         (double index);
	void IncreaseBucketCount(int num);

	KScHistogram1d& operator=(KScHistogram1d&  rhs);

	int CalcScalarImage(KScScalarImage2dUint8 *src);
	int CalcScalarImage(KScData2dUint8 *src);
};

#endif
