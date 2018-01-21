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


#pragma once

using namespace cv;
using namespace std;

class FindSquare {
public:
	FindSquare() {};
	void findSquares(const Mat& image); // Wyjeba³em static jak cos to trza dodaæ
	Point2f getVector(int temp);
	bool errorFrameNotFoundFlag = true;
	bool getErrorFrameNotFoundFlag();
private:
	double angle(Point pt1, Point pt2, Point pt0); // Wyjeba³em static jak cos to trza dodaæ
	int thresh = 50, N = 5;
	vector<vector<Point> > squares;
	void setErrorFrameNotFoundFlag(bool flag);
	
};