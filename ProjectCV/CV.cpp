#include "CV.h"

using namespace std;
using namespace cv;

bool CV::CVFrame() {
	openCam();
	while (findSquare.getErrorFrameNotFoundFlag()) {
		
		frameFinder.saveBinaryImg(vCapture);
		image = imread("FrameImage.jpg", 1);

		findSquare.findSquares(image);
		_getch();
	}
	flag = findSquare.getErrorFrameNotFoundFlag(); 
	cvDestroyWindow("FrameView");
	cvDestroyWindow("trackbars");
	closeCam();
	return flag;
}

int CV::CVFlash(Mat imgReaded) {
	
	viewTransformation.matTransformation(imgReaded, findSquare);
	Mat normalizedImg = viewTransformation.getOutputImgToFlashFinder();
	flashFinder.getFlash(normalizedImg);
	int index = flashFinder.getIndex();
	return index;
};

void CV::openCam() {
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, finder.WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, finder.WINDOW_HEIGHT);
}

void CV::closeCam() {
	vCapture.release();
}