#include "Finder.h"
#include "FrameFinder.h"

using namespace std;
using namespace cv;

void FrameFinder::saveBinaryImg() {
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, finder.WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, finder.WINDOW_HEIGHT);

	while (!kbhit()) {
		vCapture.read(finder.imgOriginal);

		inRange(finder.imgOriginal, Scalar(H_MIN_1, S_MIN_1, V_MIN_1), Scalar(H_MAX_1, S_MAX_1, V_MAX_1), finder.binaryImg1);
		inRange(finder.imgOriginal, Scalar(H_MIN_2, S_MIN_2, V_MIN_2), Scalar(H_MAX_2, S_MAX_2, V_MAX_2), finder.binaryImg2);
		add(finder.binaryImg1, finder.binaryImg2, finder.binaryImg);
		resize(finder.imgOriginal, finder.imgOriginal, Size(finder.WINDOW_WIDTH, finder.WINDOW_HEIGHT));

		if (finder.useMorphOps) {
			finder.morphOps(finder.binaryImg);
		}

		imshow("FrameView", finder.binaryImg);
		waitKey(30);
	}
	imwrite("../testImages/1.jpg", finder.binaryImg);
};