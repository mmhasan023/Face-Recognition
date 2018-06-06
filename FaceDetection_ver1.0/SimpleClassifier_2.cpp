#include "stdafx.h"
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
#include "IntImage.h"
#include "SimpleClassifier.h"
#include "AdaBoostClassifier.h"
#include "CascadeClassifier.h"
#include "Global.h"
#include "FFS.h"
#include "learn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void SimpleClassifier::ReadFromFile(ifstream& f)
{
	f>>thresh>>parity>>type;
	f>>x1>>x2>>x3>>x4>>y1>>y2>>y3>>y4;
	f.ignore(256,'\n');
	ASSERT(parity == 0 || parity == 1);
	ASSERT(type>=0 && type<=4);
}

void SimpleClassifier::WriteToFile(ofstream& f) const
{
	f<<thresh<<" ";
	f<<parity<<" ";
	f<<type<<" ";
	f<<x1<<" ";
	f<<x2<<" ";
	f<<x3<<" ";
	f<<x4<<" ";
	f<<y1<<" ";
	f<<y2<<" ";
	f<<y3<<" ";
	f<<y4<<" ";
	f<<endl;
}
