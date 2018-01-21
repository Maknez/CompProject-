#include "Finder.h"
#include "FlashFinder.h"
#include "ViewTransformation.h"
using namespace std;
using namespace cv;

void FlashFinder::getFlash(Mat imgOriginal) {



	inRange(imgOriginal, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), finder.binaryImg);
	if (finder.useMorphOps) {
		finder.morphOps(finder.binaryImg);
	}
	HoughCircles(finder.binaryImg, v3fCircles, CV_HOUGH_GRADIENT, 2, finder.binaryImg.rows / 4, 40, 20, 5, 400);

	if (v3fCircles.size() > 0) {
		for (int i = 0; i < v3fCircles.size(); i++) {
			p.x = (int)v3fCircles[0][0];
			p.y = (int)v3fCircles[0][1];
			poziomXpoczatek.x = (int)(v3fCircles[0][0] - 10);
			poziomXpoczatek.y = (int)v3fCircles[0][1];
			poziomXkoniec.x = (int)(v3fCircles[0][0] + 10);
			poziomXkoniec.y = (int)v3fCircles[0][1];
			poziomYpoczatek.x = (int)v3fCircles[0][0];
			poziomYpoczatek.y = (int)(v3fCircles[0][1] - 10);
			poziomYkoniec.x = (int)v3fCircles[0][0];
			poziomYkoniec.y = (int)(v3fCircles[0][1] + 10);
			line(imgOriginal, poziomXpoczatek, poziomXkoniec, Scalar(0, 0, RED_COLOR), 2, 8, 0);
			line(imgOriginal, poziomYpoczatek, poziomYkoniec, Scalar(0, 0, RED_COLOR), 2, 8, 0);
		}
		setIndex();
	}	
	
	waitKey(30);

	imshow("Original", imgOriginal);
	imshow("FlashView", finder.binaryImg);
	
};

void FlashFinder::setIndex() {
	indexX = ((width - p.x) / width) * 3;
	indexY = (p.y / height) * 4;
	index = ((int)indexY * 3) + (int)indexX;
}
int FlashFinder::getIndex()
{
	if (index == poprzedniIndex) {
		index = -1;
		return index;
	}
	else {
		poprzedniIndex = index;
		return index;
	}
};