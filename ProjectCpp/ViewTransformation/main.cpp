#include "Finder.h"
#include "FindSquare.h"
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


Finder* finder;
FindSquare* findSquare;
ViewTransformation* viewTransformation;

const char* wndname = "PrototypeAppView";


using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
	findSquare = new FindSquare();
	finder = new Finder();
	viewTransformation = new ViewTransformation();
	Mat image;
	//vector<vector<Point> > squares;
	
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

	//cout << findSquare->getVector(1);
	viewTransformation->matTransformation(image, *findSquare);

	Mat temp = viewTransformation->getOutputImgToFlashFinder();
	
	imshow("orgin", image);
	imshow("wynik", temp);

	waitKey(30);
	
	system("PAUSE");

	return 0;
}