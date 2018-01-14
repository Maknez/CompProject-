#include "Finder.h"
#include "CV.h"
#include "FindSquare.h"
#include "FrameFinder.h"
#include "FlashFinder.h"
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
FlashFinder* flashfinder;
ViewTransformation* viewTransformation;

const char* wndname = "PrototypeAppView";


using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {

	VideoCapture vCapture;

	findSquare = new FindSquare();
	finder = new Finder();
	viewTransformation = new ViewTransformation();
	framefinder = new FrameFinder();
	flashfinder = new FlashFinder();

	Mat image;
	Mat imgOriginal;

	/*
	while (findSquare->getErrorFrameNotFoundFlag()) {
		framefinder->saveBinaryImg();
		image = imread("1.jpg", 1);

		findSquare->findSquares(image);
		_getch();
	}
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, finder->WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, finder->WINDOW_HEIGHT);
	while (true) {

		vCapture.read(finder->imgOriginal);
		viewTransformation->matTransformation(finder->imgOriginal, *findSquare);
		Mat normalizedImg = viewTransformation->getOutputImgToFlashFinder();
		flashfinder->getFlash(normalizedImg);
		int index = flashfinder->getIndex();
		if (index != -1) {
			cout << index << endl;
		}

	}
*/	int i = (550 / 800) * 4;
	cout << i;
	//viewTransformation->matTransformation(image, *findSquare);
	//Mat normalizedImg = viewTransformation->getOutputImgToFlashFinder();
	
	
	//computerVision = new CV();
	//computerVision->CVFrame();
	system("PAUSE");
	return 0;
}