#ifndef __KSDATA_H__
#define __KSDATA_H__

#include "KScObject.h"
//#include "stdio.h"

typedef unsigned char	KSdUint8;
typedef char			KSdInt8;
typedef short			KSdInt16;
typedef int				KSdInt32;
typedef float			KSdFloat;
typedef double			KSdDouble;
typedef long double		KSdLdouble;

typedef struct tagKS_RECT
{
    int	sx;
    int	sy;
    int	ex;
    int	ey;
} KS_RECT, *KS_PRECT;

typedef struct tagKS_2D_SIZE
{
    int	dx;
    int	dy;
} KS_2D_SIZE, *KS_2D_PSIZE;

typedef struct tagKS_3D_SIZE
{
    int	dx;
    int	dy;
    int	dz;
} KS_3D_SIZE, *KS_3D_PSIZE;

typedef struct tagKS_2D_POINT
{
    int x;
    int y;
} KS_2D_POINT, *KS_2D_PPOINT;

typedef struct tagKS_3D_POINT
{
    int x;
    int y;
    int z;
} KS_3D_POINT, *KS_3D_PPOINT;

typedef struct tagKS_RGB
{
    KSdUint8 r;
    KSdUint8 g;
    KSdUint8 b;
} KS_RGB, *KS_PRGB;

typedef KS_RGB	KSdRgb;	

typedef struct tagKS_CMY
{
    KSdUint8 c;
    KSdUint8 m;
    KSdUint8 y;
} KS_CMY, *KS_PCMY;

typedef KS_CMY	KSdCmy;	

typedef struct tagKS_CMYK
{
    KSdUint8 c;
    KSdUint8 m;
    KSdUint8 y;
    KSdUint8 k;
} KS_CMYK, *KS_PCMYK;

typedef KS_CMYK	KSdCmyk;	

typedef struct tagKS_HSI
{
    KSdFloat h;
    KSdFloat s;
    KSdFloat i;
} KS_HSI, *KS_PHSI;

typedef KS_HSI KSdHsi;	

typedef struct tagKS_HLS
{
    KSdFloat h;
    KSdFloat l;
    KSdFloat s;
} KS_HLS, *KS_PHLS;

typedef KS_HLS KSdHls;	

typedef struct tagKS_YCbCr
{
    KSdFloat Y;
    KSdFloat Cb;
    KSdFloat Cr;
} KS_YCBCR, *KS_PYCBCR;

typedef KS_YCBCR KSdYCbCr;	

typedef struct tagKS_COMPLEX_FLOAT
{
    KSdFloat r;
    KSdFloat i;
} KS_COMPLEX, KS_COMPLEX_FLOAT, *KS_PCOMPLEX;

typedef KS_COMPLEX	KSdComplex;	

typedef struct tagKS_COMPLEX_DOUBLE
{
    KSdDouble r;
    KSdDouble i;
} KS_COMPLEX_DOUBLE, *KS_PCOMPLEX_DOUBLE;

typedef KS_COMPLEX			KSdComplex;	
typedef KS_COMPLEX_FLOAT	KSdComplexFloat;	
typedef KS_COMPLEX_DOUBLE	KSdComplexDouble;	

#define R_PLANE				0
#define G_PLANE				1
#define B_PLANE				2

#define C_PLANE				0
#define M_PLANE				1
#define Y_PLANE				2
#define K_PLANE				3

#define H_PLANE				0
#define S_PLANE				1
#define I_PLANE				2

#define HLS_H_PLANE			0
#define HLS_L_PLANE			1
#define HLS_S_PLANE			2

#define Yc_PLANE			0
#define Cb_PLANE			1
#define Cr_PLANE			2

#define REAL_PLANE			0
#define IMAGINARY_PLANE		1

#define KS_COPY_MODE				0
#define KS_REMAP_MODE				1
#define KS_BITMAP_MODE				2 // bitmap mode used ROI

// color image class를 위한 매크로
#define KS_RGB_PLANE_NUM			3
#define KS_RGB_INDEX_PLANE_NUM		1
#define KS_CMY_PLANE_NUM			3
#define KS_CMYK_PLANE_NUM			4
#define KS_HSI_PLANE_NUM			3
#define KS_HLS_PLANE_NUM			3
#define KS_YIQ_PLANE_NUM			3
#define KS_YUV_PLANE_NUM			3
#define KS_YCbCr_PLANE_NUM			3

#define KS_LOOKUP_TABLE_NUM			256

#define KS_Min(a,b)           (((a) < (b)) ? (a) : (b))
#define KS_Max(a,b)           (((a) > (b)) ? (a) : (b))

#define KS_MinOf3(a, b, c)    KS_Min( KS_Min( a, b), c)
#define KS_MaxOf3(a, b, c)    KS_Max( KS_Max( a, b), c)

typedef struct tagKS_IMAGESIZE 
{
	int dx;
	int dy;
	int dz;
} KS_IMAGE_SIZE;

typedef struct tagKS_ROIRECT
{
    int	sx;
    int	sy;
    int	ex;
    int	ey;
} KS_ROIRECT;

typedef struct tagKS_FILEHEADER
{
	float version;		// file의 버전 정보 저장 ....
	int   fileID;
	int   frameNum;		// 하나의 파일에 몇개의 프레임을 넣는지 저장...

	KS_IMAGE_SIZE size;
	KS_IMAGE_SIZE realSize;

	int    bpu;
	int    plane;
	int    lktNum;
	double scale;

	int        isRoi;
	int        roiMode;
	KS_ROIRECT roiRect;

	char className[CLASS_NAME_LENGTH];
	char comment[CLASS_COMMENT_LENGTH];
} KS_FILE_HERADER;

class KS_CLASS KScData : public KScObject 
{

// attribute
public:

	int dx;	// iue에서는 i, j, k로 각 차원의 길이를 나타냄...
	int dy;
	int dz;
	
	int bpu; // bytes per unit
	int dim;

	double scale;

// methods
private:


public:

	KScData(void);
	KScData(char *szName);	// 19991223 상헌 추가 
	virtual	~KScData(void);

	// bpu의 설정은 각 하위 클래스에서 실시 ...
	virtual int GetBytesPerUnit(void);

	// dx, dy, dz의 설정은 메모리 설정시에만 할 수 있음 .
	virtual int GetXSize(void);
	virtual int GetYSize(void);
	virtual int GetZSize(void);

	int GetDimension(void);

	double GetScale(void);
	int SetScale(double newScale);

	//virtual int get_max_scale(void) { return max_scale; }
	//virtual int get_min_scale(void) { return min_scale; }
	
protected:

	// 하위 클래스에서 설정 변경을 위해서만 사용...
	void SetDimension(int dimension);
	void SetBytesPerUnit(int unit);

	void SetXSize(int xSize);
	void SetYSize(int ySize);
	void SetZSize(int zSize);
};

#endif