#include "Finder.h"
#include "FrameFinder.h"

using namespace std;
using namespace cv;

void FrameFinder::saveBinaryImg(VideoCapture vCapture) {
	createBars();
	cout << "Press any button to make a photo" << endl;
	while (!kbhit()) {
		Mat imgOriginal;
		vCapture.read(imgOriginal);
		inRange(imgOriginal, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), finder.binaryImg1);
		//inRange(imgOriginal, Scalar(H_MIN_2, S_MIN_2, V_MIN_2), Scalar(H_MAX_2, S_MAX_2, V_MAX_2), finder.binaryImg2);
		add(finder.binaryImg1, finder.binaryImg1, finder.binaryImg);
		resize(imgOriginal, imgOriginal, Size(finder.WINDOW_WIDTH, finder.WINDOW_HEIGHT));

		if (finder.useMorphOps) {
			finder.morphOps(finder.binaryImg);
		}
		waitKey(30);
		imshow("FrameView", finder.binaryImg);
	}
	cout << "Your photo has been saved in FrameImage.jpg" << endl;

	imwrite("FrameImage.jpg", finder.binaryImg);

};

void FrameFinder::on_trackbar(int, void*) {};

void FrameFinder::createBars() {
	namedWindow("trackbars", 0);
	moveWindow("trackbars", 600, 300);
	char TrackbarName[20];
	sprintf(TrackbarName, "H_MIN", 0);
	sprintf(TrackbarName, "H_MAX", 255);
	sprintf(TrackbarName, "S_MIN", 0);
	sprintf(TrackbarName, "S_MAX", 255);
	sprintf(TrackbarName, "V_MIN", 0);
	sprintf(TrackbarName, "V_MAX", 255);


	createTrackbar("H_MIN", "trackbars", &H_MIN, 255, NULL);
	createTrackbar("H_MAX", "trackbars", &H_MAX, 255, NULL);
	createTrackbar("S_MIN", "trackbars", &S_MIN, 255, NULL);
	createTrackbar("S_MAX", "trackbars", &S_MAX, 255, NULL);
	createTrackbar("V_MIN", "trackbars", &V_MIN, 255, NULL);
	createTrackbar("V_MAX", "trackbars", &V_MAX, 255, NULL);

};

