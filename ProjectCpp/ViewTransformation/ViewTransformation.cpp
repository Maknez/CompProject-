#include "Finder.h"
#include "FindSquare.h"
#include "ViewTransformation.h"

using namespace std;
using namespace cv;

Mat ViewTransformation::getOutputImgToFlashFinder() {

	return outputImgToFlashFinder;
}

void ViewTransformation::matTransformation(Mat image, FindSquare& findSquare) {
	
	sortVector(findSquare);
	/*
	src[0].x = 250;
	src[0].y = 100;
	src[1].x = 500;
	src[1].y = 500;
	src[2].x = 490;
	src[2].y = 120;
	src[3].x = 230;
	src[3].y = 510;
	*/
	dst[2].x = 0;
	dst[2].y = 0;
	dst[0].x = 600;
	dst[0].y = 800;
	dst[3].x = 600;
	dst[3].y = 0;
	dst[1].x = 0;
	dst[1].y = 800;
	/*Mat 
		warpPerspectiveSrcImg = imread("1.jpg", 1);
	if (warpPerspectiveSrcImg.empty()) {
		cout << "error: image not read from file\n\n";
		system("PAUSE");
	}*/
	//Mat warpPerspectiveSrcImg = finder.imgOriginal;


	Mat warpPerspectiveSrcImg = image;
	transformMatrix = getPerspectiveTransform(src, dst);
	warpPerspective(warpPerspectiveSrcImg, outputImgToFlashFinder, transformMatrix, outputImgToFlashFinder.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar());

}



void ViewTransformation::sortVector(FindSquare& findSquare) {
	Point2f temp[4];
	float x = 0, y = 0
		;

	for (int i = 0; i < 4; i++) {
		temp[i].x = findSquare.getVector(i).x;
		temp[i].y = findSquare.getVector(i).y;
		x += temp[i].x;
		y += temp[i].y;
	}

	x = x / 4;
	y = y / 4;

	for (int i = 0; i < 4; i++) {
		if (temp[i].x < x && temp[i].y < y) {
			src[2].x = temp[i].x;
			src[2].y = temp[i].y;
		}
		else if (temp[i].x < x && temp[i].y > y) {
			src[1].x = temp[i].x;
			src[1].y = temp[i].y;
		}
		else if (temp[i].x > x && temp[i].y > y) {
			src[0].x = temp[i].x;
			src[0].y = temp[i].y;
		}
		else if (temp[i].x > x && temp[i].y < y) {
			src[3].x = temp[i].x;
			src[3].y = temp[i].y;
		}
	}
	
}
