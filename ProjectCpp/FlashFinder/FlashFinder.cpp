#include "Finder.h"
#include "FlashFinder.h"

using namespace std;
using namespace cv;

Point FlashFinder::getFlash(const vector<vector<Point> >& squares) {

	inRange(finder.imgOriginal, Scalar(0, 0, RED_COLOR), finder.binaryImg);

	if (finder.useMorphOps) {
		finder.morphOps(finder.binaryImg);
	}
	HoughCircles(finder.binaryImg, v3fCircles, CV_HOUGH_GRADIENT, 2, finder.binaryImg.rows / 4, 40, 20, 5, 400);

	if (v3fCircles.size() == 0) {
		p.x = -1;
		p.y = -1;
		waitKey(30);
		imshow("ABCORIGINAL", finder.imgOriginal);
		imshow("FlashView", finder.binaryImg);

		return p;
	}
	else {
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
			line(finder.imgOriginal, poziomXpoczatek, poziomXkoniec, Scalar(0, 0, 255), 2, 8, 0);
			line(finder.imgOriginal, poziomYpoczatek, poziomYkoniec, Scalar(0, 0, 255), 2, 8, 0);

			waitKey(30);
		}
		waitKey(30);

		imshow("ABCORIGINAL", finder.imgOriginal);
		imshow("FlashView", finder.binaryImg);
		return p;
	}
};