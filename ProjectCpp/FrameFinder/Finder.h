#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Finder {

public:
	Finder() {};
	Mat binaryImg;
	Mat binaryImg1;
	Mat binaryImg2;
	bool trackObjects = false;
	bool useMorphOps = true;
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	void morphOps(Mat &thresh);
};