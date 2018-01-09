#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <conio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Finder.h"
#include "FindSquare.h"

#pragma once

using namespace cv;
using namespace std;

class ViewTransformation {
public:
	ViewTransformation() {};
	Mat getOutputImgToFlashFinder();
	void matTransformation();
private:
	FindSquare findSquare;		// stad wektor wejsciowy jakas funkcja getVector() jako InputArray src w getPerspective()
	Finder finder;				// stad bedzie InputArray src do warpPerspective()
	Mat transformMatrix;		// do tego przypiszemy wynik getPerspective(),  czyli InputArray M w funkcji warpPerspective()
		
	Mat outputImgToFlashFinder; //OutputArray dst w warpPerspecitve()
	Point2f dst[4];
	float width = 600;
	float height = 800;
	Size dsize(float, float);

};