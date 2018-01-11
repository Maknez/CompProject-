#include "Finder.h"
#include "CV.h"
#include "FindSquare.h"
#include "FrameFinder.h"
#include "ViewTransformation.h"
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

CV* computerVision;
Finder* finder;
FrameFinder* framefinder;
FindSquare* findSquare;
ViewTransformation* viewTransformation;

const char* wndname = "PrototypeAppView";


using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
	/*findSquare = new FindSquare();
	finder = new Finder();
	viewTransformation = new ViewTransformation();
	framefinder = new FrameFinder();
	Mat image;
	Mat imgOriginal;


	while (findSquare->getErrorFrameNotFoundFlag()) {
		framefinder->saveBinaryImg();
		image = imread("1.jpg", 1);
		if (image.empty()) {
			cout << "error: image not read from file\n\n";
			system("PAUSE");
		}
		try {

			findSquare->findSquares(image);
		}
		catch (Exception e) {
			cout << e.code << endl;
		}
	}
	VideoCapture vCapture;
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, finder->WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, finder->WINDOW_HEIGHT);
	
	


	viewTransformation->matTransformation(image, *findSquare);
	Mat normalizedImg = viewTransformation->getOutputImgToFlashFinder();
	
	*/
	computerVision = new CV();
	computerVision->CVFrame();
	system("PAUSE");
	return 0;
}