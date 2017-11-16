#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <conio.h>

using namespace cv;
using namespace std;

const int FRAME_WIDTH = 576;
const int FRAME_HEIGHT = 1024;


int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;

void morphOps(Mat &thresh) {

	Mat erodeElement = getStructuringElement(MORPH_RECT, Size(1, 1));
	Mat dilateElement = getStructuringElement(MORPH_RECT, Size(12, 12));

	erode(thresh, thresh, erodeElement);
	erode(thresh, thresh, erodeElement);

	dilate(thresh, thresh, dilateElement);
	dilate(thresh, thresh, dilateElement);
}

int main(int argc, char** argv)
{
	Mat imgOriginal;		// input image
	Mat hsvImg;   // macierz widoku w kolorach HSV
	Mat binaryImg; // macierz widoku obrazu binarnego
	Mat binaryImg1; // macierz widoku obrazu binarnego
	Mat binaryImg2; // macierz widoku obrazu binarnego


	

	String zmiennaWejsciowa = argv[1];
	cout << zmiennaWejsciowa << endl;
	imgOriginal = cv::imread("TestImages/FrameImages/InputTestImages/" + zmiennaWejsciowa + ".jpg");
	if (imgOriginal.empty()) {                                  // if unable to open image
		std::cout << "error: image not read from file\n\n";     // show error message on command line
		_getch();                                               // may have to modify this line if not using Windows
		return(0);                                              // and exit program
	}


	bool trackObjects = false;
	bool useMorphOps = true;


	cvtColor(imgOriginal, hsvImg, COLOR_BGR2HSV);
	inRange(hsvImg, Scalar(0, 208, 0), Scalar(255, 226, 255), binaryImg1);
	inRange(hsvImg, Scalar(0, 208, 0), Scalar(255, 226, 255), binaryImg2);
	add(binaryImg1, binaryImg2, binaryImg);
	resize(imgOriginal, imgOriginal, Size(FRAME_WIDTH, FRAME_HEIGHT));
	resize(hsvImg, hsvImg, Size(FRAME_WIDTH, FRAME_HEIGHT));
	if (useMorphOps)
		morphOps(binaryImg);
	//imshow("binary", binaryImg);
	//imshow("normal view", imgOriginal);
	//imshow("hsv view", hsvImg);
	waitKey(30);
	imwrite("TestImages/FrameImages/OutputTestImages/" + zmiennaWejsciowa + "OutputImageTest.jpg", binaryImg);


	return 0;
}
