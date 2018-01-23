#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <conio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

class Finder {

public:
	Finder() {};
	Mat imgOriginal;
	Mat binaryImg;
	Mat binaryImg1;
	Mat binaryImg2;
	bool trackObjects = false;
	bool useMorphOps = true;

	 const int WINDOW_WIDTH = 1280;
	 const int WINDOW_HEIGHT = 720;

	void morphOps(Mat &thresh);
};