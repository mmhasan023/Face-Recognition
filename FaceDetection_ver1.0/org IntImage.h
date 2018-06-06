#define USE_DOUBLE

#ifdef USE_DOUBLE
	typedef double REAL;
#else
	typedef float REAL;
#endif

class IntImage
{
public:
	IntImage();
	~IntImage();

	void Clear(void); 
	void SetSize(const CSize size);
	IntImage& operator=(const IntImage& source);
	void CalcSquareAndIntegral(IntImage& square,IntImage& image) const;
	void CalculateVarianceAndIntegralImageInPlace(void);
	void Resize(IntImage &result,  REAL ratio) const;
	void Copy(const IntImage& source);
	void Load(const CString& filename);
	void Save(const CString& filename) const;

public:
	int height; // height, or, number of rows of the image
	int width;  // width, or, number of columns of the image
	REAL** data;  // auxiliary pointers to accelerate the read/write of the image
	                // no memory is really allocated, use memory in (buf)
					// data[i][j] is a pixel's gray value in (i)th row and (j)th column
	REAL* buf;    // pointer to a block of continuous memory containing the image
	REAL variance;
	int label;
};

void SwapIntImage(IntImage& i1,IntImage& i2);