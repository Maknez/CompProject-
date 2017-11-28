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

using namespace cv;
using namespace std;

const int FRAME_WIDTH = 896;
const int FRAME_HEIGHT = 504;

void morphOps(Mat &thresh) {

	Mat erodeElement = getStructuringElement(MORPH_RECT, Size(1, 1));
	Mat dilateElement = getStructuringElement(MORPH_RECT, Size(12, 12));
	erode(thresh, thresh, erodeElement);
	erode(thresh, thresh, erodeElement);
	dilate(thresh, thresh, dilateElement);
	dilate(thresh, thresh, dilateElement);
}

void frameFinder(Mat imgOriginal) {
	Mat hsvImg;
	Mat binaryImg;
	Mat binaryImg1;
	Mat binaryImg2;


	bool trackObjects = false;
	bool useMorphOps = true;

	cvtColor(imgOriginal, hsvImg, COLOR_BGR2HSV);
	inRange(hsvImg, Scalar(168, 123, 0), Scalar(255, 256, 255), binaryImg1);
	inRange(hsvImg, Scalar(35, 208, 121), Scalar(255, 255, 255), binaryImg2);
	add(binaryImg1, binaryImg2, binaryImg);
	resize(imgOriginal, imgOriginal, Size(FRAME_WIDTH, FRAME_HEIGHT));
	resize(hsvImg, hsvImg, Size(FRAME_WIDTH, FRAME_HEIGHT));

	if (useMorphOps)
		morphOps(binaryImg);
	waitKey(30);
	imshow("BinaryView", binaryImg);

}


int main(int argc, char** argv) {

	//Point point = flashFinder();

	Mat imgOriginal;
	VideoCapture vCapture;
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, FRAME_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);
	while (1) {
			vCapture.read(imgOriginal);
			frameFinder(imgOriginal);

	}
	return 0;
}