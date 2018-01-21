#include "FrameFinder.h"
#include "FindSquare.h"

//#include "FlashFinder.h"

#pragma once
using namespace cv;
using namespace std;

class CV {

public:
	CV() {};
	bool CVFrame();
	int CVFlash();
	Mat image;
	FrameFinder frameFinder;
	//FlashFinder* flashFinder;
	FindSquare findSquare;
	bool flag;
private:

};