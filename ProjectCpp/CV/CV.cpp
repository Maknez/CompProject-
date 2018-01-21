#include "CV.h"

using namespace std;
using namespace cv;

bool CV::CVFrame() {
	while (findSquare.getErrorFrameNotFoundFlag()) {
		//frameFinder->saveBinaryImg();
		image = imread("1.jpg", 1);
		if (image.empty()) {
			cout << "error: image not read from file\n\n";
			system("PAUSE");
		}
		try {

			findSquare.findSquares(image);
		}
		catch (Exception e) {
			cout << e.code << endl;
		}
	}
	flag = findSquare.getErrorFrameNotFoundFlag(); cout << flag;
	return flag;
}

int CV::CVFlash() {

	return 0;
};