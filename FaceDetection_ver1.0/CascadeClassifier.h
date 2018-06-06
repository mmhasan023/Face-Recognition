#ifndef __CASCADE_CLASSIFIER_H__
#define __CASCADE_CLASSIFIER_H__

struct CascadeClassifier
{
	int count;
	AdaBoostClassifier* ac;

	CascadeClassifier();
	~CascadeClassifier();
	void Clear(void);
	CascadeClassifier& operator=(const CascadeClassifier& source);

	void WriteToFile(ofstream& f) const;
	void ReadFromFile(ifstream& f);
	void LoadDefaultCascade(void);

	virtual const int ApplyImagePatch(const IntImage& im) const;
	virtual void ApplyOriginalSize(IntImage& original) ;
	virtual void ApplyOriginalSizeForInputBoosting(const CString filename,int& pointer) const;

	void DrawResults(IntImage& image, const vector<CRect>& results) const;

	virtual const bool OneRound(const int round);
};

void PostProcess(vector<CRect>& result, const int combine_min);

#endif