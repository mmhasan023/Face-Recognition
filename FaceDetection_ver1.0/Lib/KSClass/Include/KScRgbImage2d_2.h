#ifndef __KSC_RGBIMAGE2D_H__
#define __KSC_RGBIMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dUint8.h"

class KScHsiImage2d;

class KS_CLASS KScRgbImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dUint8 *pRealData[KS_RGB_PLANE_NUM]; // original image pointer
	KScData2dUint8 *pRealRoi [KS_RGB_PLANE_NUM]; // roi image pointer for copy mode

	KSdUint8       *pData    [KS_RGB_PLANE_NUM]; // access image pointer
	KSdUint8       **p2dArray[KS_RGB_PLANE_NUM]; // 2d Array
	KSdUint8       **pRoiData[KS_RGB_PLANE_NUM]; // roi image pointer

// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� ������
	////////////////////////////////////////////////////////////////////////////

	// �÷��� ��(�⺻�� : KS_RGB_PLANE_NUM)
	KScRgbImage2d(                                  int plane=KS_RGB_PLANE_NUM);

	// �̸�, �÷��� ��(�⺻�� : KS_RGB_PLANE_NUM)
	KScRgbImage2d(char *name,                       int plane=KS_RGB_PLANE_NUM);

	// ũ��, �÷��� ��(�⺻�� : KS_RGB_PLANE_NUM)
	KScRgbImage2d(            int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);

	// �̸�, ũ��, �÷��� ��(�⺻�� : KS_RGB_PLANE_NUM)
	KScRgbImage2d(char *name, int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);


	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� �ı���
	////////////////////////////////////////////////////////////////////////////
	
	virtual	~KScRgbImage2d(void);


	////////////////////////////////////////////////////////////////////////////
	// ���� �Ҵ� �� ����
	////////////////////////////////////////////////////////////////////////////
	// ���� �Ҵ�
	// ���� : ���� ũ��, ���� ũ��
	// ��ȯ : ���� - NO_ERROR or KS_OK
	//        ���� - NO_ERROR or KS_OK ���� ��, KScStatusCode.h ����
	int  Alloc(int xSize, int ySize, int plane=KS_RGB_PLANE_NUM);

	// ���� ����
	// ���� : ����
	// ��ȯ : ����
	void Free (void);


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

	KS_2D_SIZE GetSize     (void);
	int        GetXSize    (void);
	int        GetYSize    (void);


////////////////////////////////////////////////////////////////////////////
// �÷��� �� ó��
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// ���� �ʱ�ȭ
	////////////////////////////////////////////////////////////////////////////

	// ������ �÷��� ���� �־��� ������ �ʱ�ȭ
	// ���� : �ʱ�ȭ �� ��(�⺻�� : 0), �÷���(�⺻�� : R_PLANE)
	// ��ȯ : ����
	void InitTo(KSdUint8 value=0, int planeNum=R_PLANE);


	////////////////////////////////////////////////////////////////////////////
	// ���� �＼�� �Լ�
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ROI ������   : GetMain??Buffer()  - ROI ������ �ƴ� ��ü �̹����� ���� 1 ���� ������
	//                GetMain??2dArray() - ROI ������ �ƴ� ��ü �̹����� ���� 2 ���� ������
	//                Get??Buffer()      - ROI ���� �̹����� ���� 1 ���� ������
	//                Get??2dArray()     - ROI ���� �̹����� ���� 2 ���� ������
	//
	// ROI �̼����� : GetMain??Buffer(),  Get??Buffer()  - ��ü �̹����� ���� 1 ���� ������
	//                GetMain??2dArray(), Get??2dArray() - ��ü �̹����� ���� 2 ���� ������
	////////////////////////////////////////////////////////////////////////////
	KSdUint8* GetBuffer     (int planeNum);
	KSdUint8* GetRedBuffer  (void);
	KSdUint8* GetGreenBuffer(void);
	KSdUint8* GetBlueBuffer (void);

	KSdUint8* GetMainBuffer     (int planeNum);
	KSdUint8* GetMainRedBuffer  (void);
	KSdUint8* GetMainGreenBuffer(void);
	KSdUint8* GetMainBlueBuffer (void);

	KSdUint8** Get2dArray     (int planeNum);
	KSdUint8** GetRed2dArray  (void);
	KSdUint8** GetGreen2dArray(void);
	KSdUint8** GetBlue2dArray (void);

	KSdUint8** GetMain2dArray     (int planeNum);
	KSdUint8** GetMainRed2dArray  (void);
	KSdUint8** GetMainGreen2dArray(void);
	KSdUint8** GetMainBlue2dArray (void);

	////////////////////////////////////////////////////////////////////////////
	// ����Ʈ ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ �� ����
	// ���� : ��, ��ġ, �÷���
	// ��ȯ : ����
	void     SetPixel(KSdUint8 pixel,  KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdUint8 pixel,  int x, int y,       int planeNum);

	// ���� ���� Ư�� ������ �� ȹ��
	// ���� : ȹ��� �� ���� ����, ��ġ, �÷���
	// ��ȯ : ����
	void     GetPixel(KSdUint8 &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdUint8 &pixel, int x, int y,       int planeNum);
	// ���� : ��ġ, �÷���
	// ��ȯ : ȹ��� ��
	KSdUint8 GetPixel(                 KS_2D_POINT &point, int planeNum);
	KSdUint8 GetPixel(                 int x, int y,       int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// �� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� �࿡ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ������ ����, �÷���
	// ��ȯ : ����
	void PutRow(KSdUint8* row, int y, int x, int len, int planeNum);	

	// ���� ���� Ư�� �࿡ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ȹ���� ����, �÷���
	// ��ȯ : ����
	void GetRow(KSdUint8* row, int y, int x, int len, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// ���� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��, �÷���
	// ��ȯ : ����
	void SetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);

	// ���� ���� Ư�� ������ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��, �÷���
	// ��ȯ : ����
	void GetSection(KSdUint8* section, int x, int y, int xSize, int ySize, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� �޸𸮰� �Ҵ��� �Ǿ� ���� �ʰų� ũ�Ⱑ ���� Ʋ�� ����
	// ���簡 ���� ����.
	// ����� ���� ���븸 ����Ǹ�, Ŭ������ �ٸ� ������ ���� ���� ����
	////////////////////////////////////////////////////////////////////////////

	// ���� �÷����� KScScalarImage2dUint8 Ŭ������ ���۷� ����
	// ���� : �÷���, ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void CopyToScalarImage (int planeNum, KScScalarImage2dUint8 *dst);

	// KScScalarImage2dUint8 Ŭ�����κ��� ���� �÷������� ���۸� ����
	// ���� : �÷���, ���۸� ������ KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SetFromScalarImage(int planeNum, KScScalarImage2dUint8 *dst);


	////////////////////////////////////////////////////////////////////////////
	// ���� �и�
	////////////////////////////////////////////////////////////////////////////

	// ���� �÷����� KScScalarImage2dUint8 Ŭ������ ���۷� ����, CopyToScalarImage�� ����
	// ���� : �÷���, ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SplitPlane     (int planeNum, KScScalarImage2dUint8 *dst);

	// ��� �÷����� 3 ���� KScScalarImage2dUint8 Ŭ������ ���۷� ����
	// ���� : Red   �÷��� ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������,
	//        Green �÷��� ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������,
	//        Blue  �÷��� ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SplitAllPlane  (KScScalarImage2dUint8 *R,
		                 KScScalarImage2dUint8 *G,
						 KScScalarImage2dUint8 *B);

	// Red �÷����� KScScalarImage2dUint8 Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SplitRedPlane  (KScScalarImage2dUint8 *dst);
	
	// Green �÷����� KScScalarImage2dUint8 Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SplitGreenPlane(KScScalarImage2dUint8 *dst);

	// Blue �÷����� KScScalarImage2dUint8 Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void SplitBluePlane (KScScalarImage2dUint8 *dst);


	////////////////////////////////////////////////////////////////////////////
	// ���� ����
	////////////////////////////////////////////////////////////////////////////

	// KScScalarImage2dUint8 Ŭ���� ���۸� ������ �÷��ο� ����
	// ���� : �÷���, ������ ���۸� ���� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void MergePlane     (int planeNum, KScScalarImage2dUint8 *src);

	// KScScalarImage2dUint8 Ŭ���� ���۸� ������ �� �÷��ο� ����
	// ���� : ������ ���۸� ���� 3 ���� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void MergeAllPlane  (KScScalarImage2dUint8 *R,
		                 KScScalarImage2dUint8 *G,
						 KScScalarImage2dUint8 *B);

	// KScScalarImage2dUint8 Ŭ���� ���۸� ������ Red �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void MergeRedPlane  (KScScalarImage2dUint8 *dst);
	
	// KScScalarImage2dUint8 Ŭ���� ���۸� ������ Green �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void MergeGreenPlane(KScScalarImage2dUint8 *dst);
	
	// KScScalarImage2dUint8 Ŭ���� ���۸� ������ Blue �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dUint8 Ŭ���� ������
	// ��ȯ : ����
	void MergeBluePlane (KScScalarImage2dUint8 *dst);


////////////////////////////////////////////////////////////////////////////
// �ټ��� �÷��� �� ó��
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// ���� �ʱ�ȭ
	////////////////////////////////////////////////////////////////////////////

	// ���� ��ü�� �־��� ������ �ʱ�ȭ
	// ���� : �ʱ�ȭ �� ��
	// ��ȯ : ����
	void InitTo(KSdRgb value);
	
	// ���� ���� Ư�� ������ �� ����
	// ���� : ��, ��ġ
	// ��ȯ : ����
	void   SetPixel(KSdRgb pixel,  KS_2D_POINT &point);
	void   SetPixel(KSdRgb pixel,  int x, int y);

	// ���� ���� Ư�� ������ �� ȹ��
	// ���� : ȹ��� �� ���� ����, ��ġ
	// ��ȯ : ����
	void   GetPixel(KSdRgb &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdRgb &pixel, int x, int y);
	// ���� : ��ġ
	// ��ȯ : ȹ��� ��
	KSdRgb GetPixel(               KS_2D_POINT &point);
	KSdRgb GetPixel(               int x, int y);


	////////////////////////////////////////////////////////////////////////////
	// �� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� �࿡ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ������ ����
	// ��ȯ : ����
	void PutRow(KSdRgb* row, int y, int x, int len);

	// ���� ���� Ư�� �࿡ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ȹ���� ����
	// ��ȯ : ����
	void GetRow(KSdRgb* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// ���� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void SetSection(KSdRgb* section, int x, int y, int xSize, int ySize);

	// ���� ���� Ư�� ������ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void GetSection(KSdRgb* section, int x, int y, int xSize, int ySize);


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
	void CopyToObject(KScRgbImage2d *dst);

	// �ٸ� Ŭ�����κ��� ���۸� ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ����
	void SetFromObject(KScRgbImage2d *src);


	////////////////////////////////////////////////////////////////////////////
	// ���� ��ȯ
	////////////////////////////////////////////////////////////////////////////

	// KScRgbImage2d -> KScScalarImage2dUint8�� ��ȯ
	// Gray = R * 0.333 + G * 0.333 + B * 0.333
	void ConvertToScalarImage(KScScalarImage2dUint8 *dst);

	// KScRgbImage2d -> KScHsiImage2d�� ��ȯ
	void ConvertToHsiImage   (KScHsiImage2d *dst);

	// R,G,B�� ���� H, S, I�� ��ȯ
	void RgbToHsi            (KSdFloat r,  KSdFloat g,  KSdFloat b,
		                      KSdFloat *h, KSdFloat *s, KSdFloat *i );

	////////////////////////////////////////////////////////////////////////////
	// �ٸ� KScRgbImage2d Ŭ�����κ��� ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� ���ڷ� ���޵Ǵ� Ŭ������ ��� ������ ����
	////////////////////////////////////////////////////////////////////////////
	// �ٸ� Ŭ�������� ��� ������ ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ���� Ŭ������ Reference
	KScRgbImage2d& operator=(KScRgbImage2d &p);

	////////////////////////////////////////////////////////////////////////////
	//
	////////////////////////////////////////////////////////////////////////////
	void LoadFromFile(char *fileName);
	void SaveToFile  (char *fileName);

	void ReadFromContents(FILE* fp);
	void WriteToContents (FILE* fp);

	void ReadFromHeader  (FILE* fp);
	void WriteToHeader   (FILE* fp);
};

#endif
