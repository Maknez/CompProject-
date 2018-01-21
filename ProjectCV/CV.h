#include "FrameFinder.h"
#include "FindSquare.h"
#include "FlashFinder.h"
#include "ViewTransformation.h"

#pragma once
using namespace cv;
using namespace std;

class CV {

public:
	CV() {};
	bool CVFrame();
	int CVFlash(Mat imgReaded);
	Mat image;
	FrameFinder frameFinder;
	FlashFinder flashFinder;
	FindSquare findSquare;
	Finder finder;
	ViewTransformation viewTransformation;
	bool flag;
	VideoCapture vCapture;
	void openCam();
	void closeCam();
	Mat imgOriginal;
private:

};