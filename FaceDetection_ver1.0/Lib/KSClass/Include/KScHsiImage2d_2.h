#ifndef __KSC_HSIIMAGE2D_H__
#define __KSC_HSIIMAGE2D_H__

#include "KScColorImage2d.h"
#include "KScScalarImage2dFloat.h"

class KScRgbImage2d;

class KS_CLASS KScHsiImage2d : public KScColorImage2d
{

// attribute
public:
	KScData2dFloat* pRealData[KS_HSI_PLANE_NUM]; // original image pointer
	KScData2dFloat* pRealRoi [KS_HSI_PLANE_NUM]; // roi image pointer for copy mode
	KSdFloat*       pData    [KS_HSI_PLANE_NUM]; // access image pointer
	KSdFloat**      p2dArray [KS_HSI_PLANE_NUM]; // 2d Array
	KSdFloat**      pRoiData [KS_HSI_PLANE_NUM]; // roi image pointer

// methods
public:

	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� ������
	////////////////////////////////////////////////////////////////////////////

	KScHsiImage2d(void);

	// �̸�
	KScHsiImage2d(char *name);

	// ���� ũ��, ���� ũ��
	KScHsiImage2d(int xSize, int ySize);

	// �̸�, ���� ũ��, ���� ũ��
	KScHsiImage2d(char *name, int xSize, int ySize);


	////////////////////////////////////////////////////////////////////////////
	// Ŭ���� �ı���
	////////////////////////////////////////////////////////////////////////////

	virtual	~KScHsiImage2d(void);


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
	KS_2D_SIZE GetMainSize(void);
	int        GetMainXSize(void);
	int        GetMainYSize(void);

	KS_2D_SIZE GetSize(void);
	int        GetXSize(void);
	int        GetYSize(void);

	void RgbToHsi(KSdFloat r, KSdFloat g, KSdFloat b, KSdFloat *h, KSdFloat *s, KSdFloat *i);
	void HsiToRgb(KSdFloat h, KSdFloat s, KSdFloat i, KSdFloat *r, KSdFloat *g, KSdFloat *b);

////////////////////////////////////////////////////////////////////////////
// �÷��� �� ó��
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// ���� �ʱ�ȭ
	////////////////////////////////////////////////////////////////////////////

	// ������ �÷��� ���� �־��� ������ �ʱ�ȭ
	// ���� : �ʱ�ȭ �� ��, �÷���
	// ��ȯ : ����
	void InitTo(KSdFloat value, int planeNum);

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
	KSdFloat* GetBuffer          (int planeNum);
	KSdFloat* GetHueBuffer       (void);
	KSdFloat* GetSaturationBuffer(void);
	KSdFloat* GetIntensityBuffer (void);

	KSdFloat* GetMainBuffer          (int planeNum);
	KSdFloat* GetMainHueBuffer       (void);
	KSdFloat* GetMainSaturationBuffer(void);
	KSdFloat* GetMainIntensityBuffer (void);

	KSdFloat** Get2dArray          (int planeNum);
	KSdFloat** GetHue2dArray       (void);
	KSdFloat** GetSaturation2dArray(void);
	KSdFloat** GetIntensity2dArray (void);

	KSdFloat** GetMain2dArray          (int planeNum);
	KSdFloat** GetMainHue2dArray       (void);
	KSdFloat** GetMainSaturation2dArray(void);
	KSdFloat** GetMainIntensity2dArray (void);

	////////////////////////////////////////////////////////////////////////////
	// ����Ʈ ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ �� ����
	// ���� : ��, ��ġ, �÷���
	// ��ȯ : ����
	void     SetPixel(KSdFloat pixel, KS_2D_POINT &point, int planeNum);
	void     SetPixel(KSdFloat pixel, int x, int y, int planeNum);

	// ���� ���� Ư�� ������ �� ȹ��
	// ���� : ȹ��� �� ���� ����, ��ġ, �÷���
	// ��ȯ : ����
	void     GetPixel(KSdFloat &pixel, KS_2D_POINT &point, int planeNum);
	void     GetPixel(KSdFloat &pixel, int x, int y, int planeNum);
	// ���� : ��ġ, �÷���
	// ��ȯ : ȹ��� ��
	KSdFloat GetPixel(KS_2D_POINT &point, int planeNum);
	KSdFloat GetPixel(int x, int y, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// �� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� �࿡ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ������ ����, �÷���
	// ��ȯ : ����
	void PutRow(KSdFloat* row, int y, int x, int len, int planeNum);

	// ���� ���� Ư�� �࿡ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ȹ���� ����, �÷���
	// ��ȯ : ����
	void GetRow(KSdFloat* row, int y, int x, int len, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// ���� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��, �÷���
	// ��ȯ : ����
	void SetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);

	// ���� ���� Ư�� ������ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��, �÷���
	// ��ȯ : ����
	void GetSection(KSdFloat* section, int x, int y, int xSize, int ySize, int planeNum);


	////////////////////////////////////////////////////////////////////////////
	// ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� �޸𸮰� �Ҵ��� �Ǿ� ���� �ʰų� ũ�Ⱑ ���� Ʋ�� ����
	// ���簡 ���� ����.
	// ����� ���� ���븸 ����Ǹ�, Ŭ������ �ٸ� ������ ���� ���� ����
	////////////////////////////////////////////////////////////////////////////

	// ���� �÷����� KScScalarImage2dFloat Ŭ������ ���۷� ����
	// ���� : �÷���, ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void CopyToScalarImage(int planeNum, KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat Ŭ�����κ��� ���� �÷������� ���۸� ����
	// ���� : �÷���, ���۸� ������ KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SetFromScalarImage(int planeNum, KScScalarImage2dFloat *dst);
	

	////////////////////////////////////////////////////////////////////////////
	// ���� �и�
	////////////////////////////////////////////////////////////////////////////

	// ���� �÷����� KScScalarImage2dFloat Ŭ������ ���۷� ����, CopyToScalarImage ����
	// ���� : �÷���, ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SplitPlane          (int planeNum, KScScalarImage2dFloat *dst);


	// ��� �÷����� 3 ���� KScScalarImage2dFloat Ŭ������ ���۷� ����
	// ���� : Hue        �÷��� ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������,
	//        Saturation �÷��� ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������,
	//        Intensity  �÷��� ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SplitAllPlane       (KScScalarImage2dFloat *H,
		                      KScScalarImage2dFloat *S,
							  KScScalarImage2dFloat *I);

	// Hue �÷����� KScScalarImage2dFloat Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SplitHuePlane       (KScScalarImage2dFloat *dst);

	// Saturation �÷����� KScScalarImage2dFloat Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SplitSaturationPlane(KScScalarImage2dFloat *dst);

	// Intensity �÷����� KScScalarImage2dFloat Ŭ������ ���۷� ����
	// ���� : ���۰� ����Ǿ��� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void SplitIntensityPlane (KScScalarImage2dFloat *dst);
	

	////////////////////////////////////////////////////////////////////////////
	// ���� ����
	////////////////////////////////////////////////////////////////////////////

	// KScScalarImage2dFloat Ŭ���� ���۸� ������ �÷��ο� ����
	// ���� : �÷���, ������ ���۸� ���� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void MergePlane          (int planeNum, KScScalarImage2dFloat *src);


	// KScScalarImage2dFloat Ŭ���� ���۸� ������ �� �÷��ο� ����
	// ���� : ������ ���۸� ���� 3 ���� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void MergeAllPlane       (KScScalarImage2dFloat *H,
		                      KScScalarImage2dFloat *S,
							  KScScalarImage2dFloat *I);

	// KScScalarImage2dFloat Ŭ���� ���۸� ������ Hue �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void MergeHuePlane       (KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat Ŭ���� ���۸� ������ Saturation �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void MergeSaturationPlane(KScScalarImage2dFloat *dst);

	// KScScalarImage2dFloat Ŭ���� ���۸� ������ Intensity �÷��ο� ����
	// ���� : ������ ���۸� ���� KScScalarImage2dFloat Ŭ���� ������
	// ��ȯ : ����
	void MergeIntensityPlane (KScScalarImage2dFloat *dst);

////////////////////////////////////////////////////////////////////////////
// �ټ��� �÷��� �� ó��
////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// ���� �ʱ�ȭ
	////////////////////////////////////////////////////////////////////////////

	// ���� ��ü�� �־��� ������ �ʱ�ȭ
	// ���� : �ʱ�ȭ �� ��
	// ��ȯ : ����
	void InitTo(KSdHsi value);

	// ���� ���� Ư�� ������ �� ����
	// ���� : ��, ��ġ
	// ��ȯ : ����
	void   SetPixel(KSdHsi pixel, KS_2D_POINT &point);
	void   SetPixel(KSdHsi pixel, int x, int y);


	// ���� ���� Ư�� ������ �� ȹ��
	// ���� : ȹ��� �� ���� ����, ��ġ
	// ��ȯ : ����
	void   GetPixel(KSdHsi &pixel, KS_2D_POINT &point);
	void   GetPixel(KSdHsi &pixel, int x, int y);
	// ���� : ��ġ
	// ��ȯ : ȹ��� ��
	KSdHsi GetPixel(KS_2D_POINT &point);
	KSdHsi GetPixel(int x, int y);


	////////////////////////////////////////////////////////////////////////////
	// �� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� �࿡ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ������ ����
	// ��ȯ : ����
	void PutRow(KSdHsi* row, int y, int x, int len);

	// ���� ���� Ư�� �࿡ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ȹ���� ����
	// ��ȯ : ����
	void GetRow(KSdHsi* row, int y, int x, int len);


	////////////////////////////////////////////////////////////////////////////
	// ���� ���� ó�� �Լ�
	////////////////////////////////////////////////////////////////////////////

	// ���� ���� Ư�� ������ ���� �� ����
	// ���� : ������ ���� �����ϰ� �ִ� ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void SetSection(KSdHsi* section, int x, int y, int xSize, int ySize);

	// ���� ���� Ư�� ������ ���� �� ȹ��
	// ���� : ȹ���� ���� ������ ���� ������, ���� ��ġ, ���� ��ġ, ���� ũ��, ���� ũ��
	// ��ȯ : ����
	void GetSection(KSdHsi* section, int x, int y, int xSize, int ySize);


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
	void CopyToObject(KScHsiImage2d *dst);

	// �ٸ� Ŭ�����κ��� ���۸� ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ����
	void SetFromObject(KScHsiImage2d *src);

	
	////////////////////////////////////////////////////////////////////////////
	// ���� ��ȯ
	////////////////////////////////////////////////////////////////////////////

	// KScHsiImage2d -> KScRgbImage2d ��ȯ
	void ConvertToRgbImage(KScRgbImage2d *dst);


	////////////////////////////////////////////////////////////////////////////
	// �ٸ� KScHsiImage2d Ŭ�����κ��� ���� ����
	////////////////////////////////////////////////////////////////////////////
	// ����
	//
	// ���� ����� ���ڷ� ���޵Ǵ� Ŭ������ ��� ������ ����
	////////////////////////////////////////////////////////////////////////////
	// �ٸ� Ŭ�������� ��� ������ ����
	// ���� : ���۸� ������ Ŭ���� ������
	// ��ȯ : ���� Ŭ������ Reference
	KScHsiImage2d& operator=(KScHsiImage2d &p);

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
