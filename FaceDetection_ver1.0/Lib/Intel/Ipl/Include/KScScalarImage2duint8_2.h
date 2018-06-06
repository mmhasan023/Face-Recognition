#ifndef __KSC_SCALARIMAGE2DUINT8_H__
#define __KSC_SCALARIMAGE2DUINT8_H__

#include "KScScalarImage2d.h"
#include "KScBitmapRoi2d.h"

class KScRgbImage2d;

class KS_CLASS KScScalarImage2dUint8 : public KScScalarImage2d
{

// attribute
public:
	KScData2dUint8* pRealData; // original image pointer
	KScData2dUint8* pRealRoi;  // roi image pointer for copy mode
	KSdUint8*       pData;     // access image pointer
	KSdUint8**      p2dArray;  // 2d Array
	KSdUint8**      pRoiData;  // roi image pointer
	
// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� ������
	////////////////////////////////////////////////////////////////////////////

	KScScalarImage2dUint8(void);

	// �̸�
	KScScalarImage2dUint8(char *name);
	
	// ���� ũ��, ���� ũ��
	KScScalarImage2dUint8(int xSize, int ySize);

	// �̸�, ���� ũ��, ���� ũ��
	KScScalarImage2dUint8(char *name, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� �ı���
	////////////////////////////////////////////////////////////////////////////

	virtual	~KScScalarImage2dUint8(void);


	////////////////////////////////////////////////////////////////////////////
	// ���� �Ҵ� �� ����
	////////////////////////////////////////////////////////////////////////////
	// ���� �Ҵ�
	// ���� : ���� ũ��, ���� ũ��
	// ��ȯ : ���� - NO_ERROR or KS_OK
	//        ���� - NO_ERROR or KS_OK ���� ��, KScStatusCode.h ����
	int  Alloc(int xSize, int ySize);
	
	// ���� ����
	// ���� : ����
	// ��ȯ : ����
	void Free(void);


	////////////////////////////////////////////////////////////////////////////
	// ROI(Region Of Interest) ���� �Լ�
	////////////////////////////////////////////////////////////////////////////
	
	// ROI ���� Ȯ��
	// ���� : ����
	// ��ȯ : TRUE  - ROI�� ������
	//        FALSE - ROI�� ������ �ȵ�
	virtual int  IsRoi        (void);

	// ROI ����
	// ���� : ROI ����
	// ��ȯ : ���� - NO_ERROR or KS_OK
	//        ���� - NO_ERROR or KS_OK ���� ��, KScStatusCode.h ����
	virtual int  SetRoiRect   (KS_RECT &rect);
	virtual int  SetRoiRect   (int sx, int sy, int ex, int ey);

	// ROI ���� ����
	// ���� : ����
	// ��ȯ : ����
	virtual void ResetRoiRect (void);

	// ROI ���� ������ �ش��ϴ� ���� �Ҵ�
	// ���� : ����
	// ��ȯ : ���� - NO_ERROR or KS_OK
	//        ���� - NO_ERROR or KS_OK ���� ��, KScStatusCode.h ����
	virtual int  MakeRoiBuffer(void);

	// ROI Mode ����
	// ���� : ROI Mode - KS_COPY_MODE, KS_REMAP_MODE, KS_BITMAP_MODE
	// ��ȯ : ����
	virtual void SetRoiMode   (int mode);


	////////////////////////////////////////////////////////////////////////////
	// ���� �＼�� �Լ�
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ROI ������   : GetMainBuffer()  - ROI ������ �ƴ� ��ü �̹����� ���� 1 ���� ������
	//                GetMain2dArray() - ROI ������ �ƴ� ��ü �̹����� ���� 2 ���� ������
	//                GetBuffer()      - ROI ���� �̹����� ���� 1 ���� ������
	//                Get2dArray()     - ROI ���� �̹����� ���� 2 ���� ������
	//
	// ROI �̼����� : GetMainBuffer(),  GetBuffer()  - ��ü �̹����� ���� 1 ���� ������
	//                GetMain2dArray(), Get2dArray() - ��ü �̹����� ���� 2 ���� ������
	////////////////////////////////////////////////////////////////////////////
	KSdUint8*  GetMainBuffer (void);
	KSdUint8** GetMain2dArray(void);

	KSdUint8*  GetBuffer     (void);
	KSdUint8** Get2dArray    (void);
	

	////////////////////////////////////////////////////////////////////////////
	// �̹��� ũ�� ȹ�� �Լ�
	////////////////////////////////////////////////////////////////////////////
	// ���� 1
	//
	// ROI ������   : GetMainSize()  - ROI ������ �ƴ� ��ü �̹����� ���� ũ�� ȹ��
	//                GetMainXSize() - ROI ������ �ƴ� ��ü �̹����� ���� ���� ũ�� ȹ��
	//                GetMainYSize() - ROI ������ �ƴ� ��ü �̹����� ���� ���� ũ�� ȹ��
	//                GetSize()      - ROI ���� �̹����� ���� ũ�� ȹ��
	//                GetXSize()     - ROI ���� �̹����� ���� ���� ũ�� ȹ��
	//                GetYSize()     - ROI ���� �̹����� ���� ���� ũ�� ȹ��
	//
	// ROI �̼����� : GetMainSize(),  GetSize()  - ��ü �̹����� ���� ũ�� ȹ��
	//                GetMainXSize(), GetXSize() - ��ü �̹����� ���� ���� ũ�� ȹ��
	//                GetMainYSize(), GetYSize() - ��ü �̹����� ���� ���� ũ�� ȹ��
	////////////////////////////////////////////////////////////////////////////
	// ���� 1
	//
	// Windows ���ο����� �̹��� ��½� ������ ���� ũ�Ⱑ 4�� ����� ���ȴ�.
	// ���� �Լ� �� ���� ũ�� ȹ�� �Լ��� ��ȯ���� 4�� ����̴�.
	// ������ ũ�Ⱑ 4�� ����� �ƴ� ���� ȹ���ϱ�  ���ؼ��� ������ �Լ��� ����Ѵ�.
	////////////////////////////////////////////////////////////////////////////
	// int KScGenericImage::GetRealXSize();
	// int KScGenericImage::GetRealYSize();
	// int KScGenericImage::GetRealZSize();
	KS_2D_SIZE GetMainSize (void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize (void);
	int        GetXSize(void);
	int        GetYSize(void);
	

	////////////////////////////////////////////////////////////////////////////
	// ����Ʈ ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ �� ����
	// ���� : ��, ��ġ
	// ��ȯ : ����
	void     SetPixel(KSdUint8 pixel, KS_2D_POINT &point);
	void     SetPixel(KSdUint8 pixel, int x, int y);

	// ���� ���� Ư�� ������ �� ȹ��
	// ���� : ȹ��� �� ���� ����, ��ġ
	// ��ȯ : ����
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point);
	void     GetPixel(KSdUint8 &pixel, int x, int y);
	// ���� : ��ġ
	// ��ȯ : ȹ��� ��
	KSdUint8 GetPixel(KS_2D_POINT &point);
	KSdUint8 GetPixel(int x, int y);
	

	////////////////////////////////////////////////////////////////////////////
	// �� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� �࿡ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ������ ����
	// ��ȯ : ����
	void PutRow(KSdUint8* row, int y, int x, int len);

	// ���� ���� Ư�� �࿡ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ȹ���� ����
	// ��ȯ : ����
	void GetRow(KSdUint8* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// ���� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize);

	// ���� ���� Ư�� ������ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// ���� �ʱ�ȭ
	////////////////////////////////////////////////////////////////////////////

	// ���� ��ü�� �־��� ������ �ʱ�ȭ
	// ���� : �ʱ�ȭ �� ��(�⺻�� : 0)
	// ��ȯ : ����
	void InitTo(KSdUint8 value=0);

	
	////////////////////////////////////////////////////////////////////////////
	// ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� �޸𸮰� �Ҵ��� �Ǿ� ���� �ʰų� ũ�Ⱑ ���� Ʋ�� ����
	// ���簡 ���� ����.
	// ����� ���� ���븸 ����Ǹ�, Ŭ������ �ٸ� ������ ���� ���� ����
	////////////////////////////////////////////////////////////////////////////

	// �ٸ� Ŭ������ ���۸� ����
	// ���� : ���۰� ����Ǿ��� Ŭ���� ������
	// ��ȯ : ����
	void CopyToObject (KScScalarImage2dUint8 *dst);

	// �ٸ� Ŭ�����κ��� ���۸� ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ����
	void SetFromObject(KScScalarImage2dUint8 *src);


	////////////////////////////////////////////////////////////////////////////
	// KScRgbImage2d�� ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ������ ������ KScRgbImage2d������ ��ȯ�Ͽ� ����
	// KScRgbImage2d�� �� �÷����� ���������� ����(RRR..., GGG..., BBB...)�ϸ�,
	// ���ۻ��� Ư�� ���� �� �÷����� ���� �����ϴ�.
	// ���� : ���۸� ������ KScRgbImage2d Ŭ���� ������
	// ��ȯ : ����
	void ConvertToRgbImage(KScRgbImage2d *dst);


	////////////////////////////////////////////////////////////////////////////
	// �ٸ� KScScalarImage2dUint8 Ŭ�����κ��� ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� ���ڷ� ���޵Ǵ� Ŭ������ ��� ������ ����
	////////////////////////////////////////////////////////////////////////////
	// �ٸ� Ŭ�������� ��� ������ ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ���� Ŭ������ Reference
	KScScalarImage2dUint8& operator=(KScScalarImage2dUint8 &p);

	////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////
	void LoadFromFile    (char *fileName);
	void SaveToFile      (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);
	
	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif
