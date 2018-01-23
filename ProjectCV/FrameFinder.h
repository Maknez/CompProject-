#include "Finder.h"
#pragma once

using namespace cv;
using namespace std;

class FrameFinder {

public:
	FrameFinder() {};
	void saveBinaryImg(VideoCapture vCapture);

private:
	Finder finder;
	int H_MIN = 25;
	int H_MAX = 51;
	int S_MIN = 142;
	int S_MAX = 179;
	int V_MIN = 140;
	int V_MAX = 246;
	void createBars();
	void on_trackbar(int, void*);
};