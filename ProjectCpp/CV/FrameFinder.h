#include "Finder.h"
#pragma once

using namespace cv;
using namespace std;

class FrameFinder {

public:
	FrameFinder() {};
	void saveBinaryImg();

private:
	Finder finder;
	VideoCapture vCapture;
	const int H_MIN_1 = 25;
	const int H_MAX_1 = 51;
	const int S_MIN_1 = 142;
	const int S_MAX_1 = 179;
	const int V_MIN_1 = 140;
	const int V_MAX_1 = 246;
	const int H_MIN_2 = 30;
	const int H_MAX_2 = 82;
	const int S_MIN_2 = 56;
	const int S_MAX_2 = 128;
	const int V_MIN_2 = 170;
	const int V_MAX_2 = 255;
	
};