#include "Finder.h"
#include "FrameFinder.h"

using namespace std;
using namespace cv;

void FrameFinder::saveBinaryImg() {
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, WINDOW_HEIGHT);

	while (!kbhit()) {
		vCapture.read(imgOriginal);

		inRange(imgOriginal, Scalar(H_MIN_1, S_MIN_1, V_MIN_1), Scalar(H_MAX_1, S_MAX_1, V_MAX_1), binaryImg1);
		inRange(imgOriginal, Scalar(H_MIN_2, S_MIN_2, V_MIN_2), Scalar(H_MAX_2, S_MAX_2, V_MAX_2), binaryImg2);
		add(binaryImg1, binaryImg2, binaryImg);
		resize(imgOriginal, imgOriginal, Size(WINDOW_WIDTH, WINDOW_HEIGHT));

		if (useMorphOps) {
			morphOps(binaryImg);
		}

		imshow("FrameView", binaryImg);
		waitKey(30);
	}
	imwrite("testImages/PrototypeImages/1.jpg", binaryImg);
};

void FrameFinder::morphOps(Mat &thresh) {
	Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));
	erode(thresh, thresh, erodeElement);
	erode(thresh, thresh, erodeElement);
	dilate(thresh, thresh, dilateElement);
	dilate(thresh, thresh, dilateElement);
};