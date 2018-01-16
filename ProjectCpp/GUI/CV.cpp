#include "CV.h"

using namespace std;
using namespace cv;

bool CV::CVFrame() {
	
	while (findSquare.getErrorFrameNotFoundFlag()) {
		
		//frameFinder.saveBinaryImg(finder.imgOriginal);
		image = imread("1.jpg", 1);

		findSquare.findSquares(image);
		//_getch();
	}
	flag = findSquare.getErrorFrameNotFoundFlag(); cout << flag;
	return flag;
}

int CV::CVFlash() {
	
	vCapture.read(finder.imgOriginal);
	viewTransformation.matTransformation(finder.imgOriginal, findSquare);
	Mat normalizedImg = viewTransformation.getOutputImgToFlashFinder();
	flashFinder.getFlash(normalizedImg);
	int index = flashFinder.getIndex();
	//int index = -1;
	return index;
};

void CV::openCam() {
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, finder.WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, finder.WINDOW_HEIGHT);
}