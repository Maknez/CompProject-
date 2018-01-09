#include "Finder.h"
#include "FindSquare.h"
#include "ViewTransformation.h"

using namespace std;
using namespace cv;

Mat ViewTransformation::getOutputImgToFlashFinder() {

	return outputImgToFlashFinder;
}

void ViewTransformation::matTransformation() {
	Point2f src[4];
	for (int i = 0; i < 4; i++) {
		src[i] = findSquare.getVector(i);
	}
	
	dst[0].x = 0;
	dst[0].y = 0;
	dst[1].x = 600;
	dst[1].y = 800;
	dst[2].x = 600;
	dst[2].y = 0;
	dst[3].x = 0;
	dst[3].y = 800;
	
	Mat warpPerspectiveSrcImg = finder.imgOriginal;
	transformMatrix = getPerspectiveTransform(src, dst);
	warpPerspective(warpPerspectiveSrcImg, outputImgToFlashFinder, transformMatrix, dsize(width, height), INTER_LINEAR, BORDER_CONSTANT, Scalar());
}

Size ViewTransformation::dsize(float width, float height)
{
	return Size();
}

