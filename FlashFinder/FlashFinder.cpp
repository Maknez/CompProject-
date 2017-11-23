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

String numberToString(int Number) {
	stringstream ss;
	ss << Number;
	return ss.str();
}

int main(int argc, char** argv)
{
	Mat imgOriginal; // zdjecie wejsciowe
	Mat hsvImg;   // macierz widoku w kolorach HSV
	Mat binaryImg; // macierz widoku obrazu binarnego
	Mat binaryImg1; // macierz widoku obrazu binarnego
	Mat binaryImg2; // macierz widoku obrazu binarnego
	vector<Vec3f> v3fCircles;
	Point poziomXpoczatek;
	Point poziomXkoniec;
	Point poziomYpoczatek;
	Point poziomYkoniec;
	String label;
	String zmiennaWejsciowa = argv[1];

	cout << "Obraz " << zmiennaWejsciowa << ".jpg \n";
	imgOriginal = imread("TestImages/FlashImages/InputTestImages/" + zmiennaWejsciowa + ".jpg");          // open image

	if (imgOriginal.empty()) {                                  // if unable to open image
		std::cout << "error: image not read from file\n\n";     // show error message on command line
		_getch();                                               // may have to modify this line if not using Windows
		return(0);                                              // and exit program
	}

	bool trackObjects = false;
	bool useMorphOps = true;

	cvtColor(imgOriginal, hsvImg, COLOR_BGR2HSV);
	inRange(hsvImg, Scalar(0, 0, 251), Scalar(255, 4, 255), binaryImg1);
	inRange(hsvImg, Scalar(0, 0, 251), Scalar(255, 4, 255), binaryImg2);
	add(binaryImg1, binaryImg2, binaryImg);
	resize(imgOriginal, imgOriginal, Size(FRAME_WIDTH, FRAME_HEIGHT));
	resize(hsvImg, hsvImg, Size(FRAME_WIDTH, FRAME_HEIGHT));
	if (useMorphOps)
		morphOps(binaryImg);

	HoughCircles(binaryImg,			// input image
		v3fCircles,							// function output (must be a standard template library vector
		CV_HOUGH_GRADIENT,					// two-pass algorithm for detecting circles, this is the only choice available
		2,									// size of image / this value = "accumulator resolution", i.e. accum res = size of image / 2
		binaryImg.rows / 4,				// min distance in pixels between the centers of the detected circles
		40,								// high threshold of Canny edge detector (called by cvHoughCircles)						
		20,									// low threshold of Canny edge detector (set at 1/2 previous value)
		5,									// min circle radius (any circles with smaller radius will not be returned)
		400);								// max circle radius (any circles with larger radius will not be returned)


	cout << "Point position x = " << v3fCircles[0][0] << ", y = " << v3fCircles[0][1] << "\n"; // Cross position x, y

	label = "X = " + numberToString((int)v3fCircles[0][0]) + " || Y = " + numberToString((int)v3fCircles[0][1]); // Dodawanie tekstu do Labela

	poziomXpoczatek.x = (int)(v3fCircles[0][0] - 10);
	poziomXpoczatek.y = (int)v3fCircles[0][1];
	poziomXkoniec.x = (int)(v3fCircles[0][0] + 10);
	poziomXkoniec.y = (int)v3fCircles[0][1];

	poziomYpoczatek.x = (int)v3fCircles[0][0];
	poziomYpoczatek.y = (int)(v3fCircles[0][1] - 10);
	poziomYkoniec.x = (int)v3fCircles[0][0];
	poziomYkoniec.y = (int)(v3fCircles[0][1] + 10);

	line(imgOriginal, poziomXpoczatek, poziomXkoniec, Scalar(0, 0, 255), 2, 8, 0);
	line(imgOriginal, poziomYpoczatek, poziomYkoniec, Scalar(0, 0, 255), 2, 8, 0);
	putText(imgOriginal, label, Point(10, 20), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255, 255, 255), 2.0);

	waitKey(30);
	imwrite("TestImages/FlashImages/OutputTestImages/Binary/" + zmiennaWejsciowa + "BinaryImageTest.jpg", binaryImg);
	imwrite("TestImages/FlashImages/OutputTestImages/Cross/" + zmiennaWejsciowa + "CrossImageTest.jpg", imgOriginal);

	return 0;
}