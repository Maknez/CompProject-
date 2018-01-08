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

#pragma once

using namespace cv;
using namespace std;

class FlashFinder {
public:
	FlashFinder() {};
	Point getFlash(const vector<vector<Point> >& squares);
private:
	Finder finder;
	vector<Vec3f> v3fCircles;
	Point p, poziomXpoczatek, poziomXkoniec, poziomYpoczatek, poziomYkoniec;
	const int H_MIN = 117;
	const int H_MAX = 255;
	const int S_MIN = 251;
	const int S_MAX = 255;
	const int V_MIN = 0;
	const int V_MAX = 157;
	const int RED_COLOR = 255;

};