#include "Finder.h"
#include "FrameFinder.h"

using namespace std;
using namespace cv;

void FrameFinder::saveBinaryImg(Mat imgOriginal) {

	cout << "Press any button to make a photo" << endl;
	while (!kbhit()) {
		
		inRange(imgOriginal, Scalar(H_MIN_1, S_MIN_1, V_MIN_1), Scalar(H_MAX_1, S_MAX_1, V_MAX_1), finder.binaryImg1);
		inRange(imgOriginal, Scalar(H_MIN_2, S_MIN_2, V_MIN_2), Scalar(H_MAX_2, S_MAX_2, V_MAX_2), finder.binaryImg2);
		add(finder.binaryImg1, finder.binaryImg2, finder.binaryImg);
		resize(imgOriginal, imgOriginal, Size(finder.WINDOW_WIDTH, finder.WINDOW_HEIGHT));

		if (finder.useMorphOps) {
			finder.morphOps(finder.binaryImg);
		}
		waitKey(30);
		imshow("FrameView", finder.binaryImg);
	}
	cout << "Your photo has been saved in 1.jpg" << endl;

	imwrite("1.jpg", finder.binaryImg);

};