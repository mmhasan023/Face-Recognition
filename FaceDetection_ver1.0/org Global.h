	enum TRAIN_METHODS {TRAIN_ADA = 1, TRAIN_FFS= 2};
	enum LINEAR_CLASSIFIER {LC_ORIGINAL = 1, LC_LAC = 2, LC_FDA = 3};

struct CascadeClassifier;

extern CString 	option_filename;

extern int total_fp;

extern CString trainset_filename;
extern CString validset_filename;
extern CString classifier_filename;
extern CString ada_log_filename;
extern CString cascade_filename;
extern CString FFS_WeakClassifiers_filename;
extern CString FFS_log_filename;
extern CString FileUsage_log_filename;
extern CString Bootstrap_database_filename;
extern CString Backup_directory_name;
extern CString TestSet_filename;
extern int sx;
extern int sy;
extern int train_method;
extern int linear_classifier;
extern int bootstrap_level;
extern int max_bootstrap_level;
extern vector<REAL> bootstrap_resizeratio;
extern vector<int> bootstrap_increment;
extern int totalfeatures;
extern int max_files;
extern int goal_method;
extern REAL node_det_goal;
extern REAL node_fp_goal;
extern int first_feature;
extern REAL asym_ratio;
extern int max_nodes;
extern vector<int> nof;
extern int starting_node;
extern int facecount, validfacecount;

extern IntImage* trainset;
extern IntImage* validset;
extern int totalcount;
extern int validcount;	

extern CascadeClassifier* cascade;
extern REAL* weights;
extern int** table;
extern SimpleClassifier* classifiers;

extern REAL* features;
extern int* labels;

extern int* fileused;
extern int bootstrap_size;
extern CString* bootstrap_filenames;

extern REAL mean_min,mean_max,sq_min,sq_max,var_min,var_max;

void ReadOneTrainingSample(ifstream& is,IntImage& image);
void GetFeatureValues0(REAL* const features,const int from,const int to,const int x1,const int x2,const int x3,const int y1,const int y3);
void GetFeatureValues1(REAL* const features,const int from,const int to,const int x1,const int x3,const int y1,const int y2,const int y3);
void GetFeatureValues2(REAL* const features,const int from,const int to,const int x1,const int x2,const int x3,const int x4,const int y1,const int y3);
void GetFeatureValues3(REAL* const features,const int from,const int to,const int x1,const int x3,const int y1,const int y2,const int y3,const int y4);
void GetFeatureValues4(REAL* const features,const int from,const int to,const int x1,const int x2,const int x3,const int y1,const int y2,const int y3);
void QuickSort(REAL* values,int* labels,const int lo,const int hi);
void QuickSort(REAL* values,int* labels,REAL* weights,int* parity,const int lo,const int hi);
void FillTheTable(int* const row,const SimpleClassifier& sc);
void ClearUpGlobalData(void);
const int CountTrainFaces(void);
const int CountValidFaces(void);
void ReadTrainSet(CString filename);
void ReadValidSet(CString filename);
void SaveTrainSet(CString filename);
void SaveValidSet(CString filename);
void InitializeAuxiliaryVariables();
void InitializeWeights(void);
void ReadClassifiers(void);
void InitGlobalData(void);
void NormalizeWeight(void);
void SkewWeight(const REAL skew_ratio);
void ValidateTheThreshold(AdaBoostClassifier& ada,ofstream& f);

void MatrixInversion(REAL** a,int n);
void WithinClassScatter(AdaBoostClassifier& ada);

void ReadRangeFile(void);
void WriteRangeFile(void);