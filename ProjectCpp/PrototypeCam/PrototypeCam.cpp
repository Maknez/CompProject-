#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <conio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment(lib, "Winmm.lib")

using namespace cv;
using namespace std;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
int FRAME_WIDTH;
int FRAME_HEIGHT;
int szynaczy;
int wynary;
vector<Point> organizedSquares;
int wektorX[][4];
int thresh = 50, N = 5;

const char* wndname = "PrototypeAppView";

int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;

void morphOps(Mat &thresh) {

	Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));
	erode(thresh, thresh, erodeElement);
	erode(thresh, thresh, erodeElement);
	dilate(thresh, thresh, dilateElement);
	dilate(thresh, thresh, dilateElement);
}

void frameFinder() {
	Mat hsvImg;
	Mat binaryImg;
	Mat binaryImg1;
	Mat binaryImg2;
	Mat imgOriginal;
	bool trackObjects = false;
	bool useMorphOps = true;
	VideoCapture vCapture;
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, WINDOW_HEIGHT);
	

	while (!kbhit()) {
		vCapture.read(imgOriginal);


		cvtColor(imgOriginal, hsvImg, COLOR_BGR2HSV);
		inRange(imgOriginal, Scalar(25, 142, 140), Scalar(51, 179, 246), binaryImg1);
		inRange(imgOriginal, Scalar(30, 56, 170), Scalar(82, 128, 255), binaryImg2);
		add(binaryImg1, binaryImg2, binaryImg);
		resize(imgOriginal, imgOriginal, Size(WINDOW_WIDTH, WINDOW_HEIGHT));
		resize(hsvImg, hsvImg, Size(WINDOW_WIDTH, WINDOW_HEIGHT));

		if (useMorphOps) {
			morphOps(binaryImg);
		}
		imshow("FrameView", binaryImg);
		waitKey(30);
	}
	//vCapture.release();
	imwrite("testImages/1.jpg", binaryImg);
}

String numberToString(int Number) {
	stringstream ss;
	ss << Number;
	return ss.str();
}

Mat drawGrid(Mat imgOriginal, const vector<vector<Point> >& squares) {

	szynaczy = FRAME_WIDTH / 3;
	wynary = FRAME_HEIGHT / 4;

	const Point* p = &squares[1][0];
	int n = (int)squares[1].size();
	if (p->x > 3 && p->y > 3)
		polylines(imgOriginal, &p, &n, 1, true, Scalar(0, 0, 255), 3, LINE_AA);
	
	Point p1;
	p1.x = squares[4][2].x + szynaczy;
	p1.y = squares[4][2].y;
	Point p2;
	p2.x = squares[4][2].x + szynaczy;
	p2.y = squares[4][2].y + wynary;
	line(imgOriginal, squares[1][0], squares[1][1], Scalar(0, 123, 255), 5, 8, 0);
	line(imgOriginal, squares[1][1], squares[1][2], Scalar(123, 123, 255), 5, 8, 0);
	line(imgOriginal, squares[1][2], squares[1][3], Scalar(0, 123, 0), 5, 8, 0);
	line(imgOriginal, squares[1][3], squares[1][0], Scalar(255, 123, 255), 5, 8, 0);

	return imgOriginal;
}

Point flashFinder(Mat imgOriginal, const vector<vector<Point> >& squares) {
	Mat hsvImg;
	Mat binaryImg;
	Mat binaryImg1;
	Mat binaryImg2;
	vector<Vec3f> v3fCircles;
	Point poziomXpoczatek;
	Point poziomXkoniec;
	Point poziomYpoczatek;
	Point poziomYkoniec;
	String label;
	Point p;
	bool trackObjects = false;
	bool useMorphOps = true;
	bool ifFind = false;
	//cvtColor(imgOriginal, hsvImg, COLOR_BGR2HSV);
	inRange(imgOriginal, Scalar(117, 251, 0), Scalar(255, 255, 157), binaryImg);
	if (useMorphOps)
		morphOps(binaryImg);
	HoughCircles(binaryImg, v3fCircles, CV_HOUGH_GRADIENT, 2, binaryImg.rows / 4, 40, 20, 5, 400);
	
	/*dodany if else*******************************jesli nie dziala to wyjebac************************************************************/
	
	if (v3fCircles.size() == 0) {
		p.x = -1;
		p.y = -1;
		waitKey(30);
		imshow("ABCORIGINAL", imgOriginal);
		imshow("FlashView", binaryImg);

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
			line(imgOriginal, poziomXpoczatek, poziomXkoniec, Scalar(0, 0, 255), 2, 8, 0);
			line(imgOriginal, poziomYpoczatek, poziomYkoniec, Scalar(0, 0, 255), 2, 8, 0);

			waitKey(30);
		}
		waitKey(30);
		
		imshow("ABCORIGINAL", imgOriginal);
		imshow("FlashView", binaryImg);
		return p;
	}
		
}

static double angle(Point pt1, Point pt2, Point pt0) {
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;

	return (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

// returns sequence of squares detected on the image.
// the sequence is stored in the specified memory storage
static void findSquares(const Mat& image, vector<vector<Point> >& squares)
{
	squares.clear();

	Mat pyr, timg, gray0(image.size(), CV_8U), gray;

	// down-scale and upscale the image to filter out the noise
	pyrDown(image, pyr, Size(image.cols / 2, image.rows / 2));
	pyrUp(pyr, timg, image.size());
	vector<vector<Point> > contours;

	// find squares in every color plane of the image
	for (int c = 0; c < 3; c++)
	{
		int ch[] = { c, 0 };
		mixChannels(&timg, 1, &gray0, 1, ch, 1);

		// try several threshold levels
		for (int l = 0; l < N; l++)
		{
			// hack: use Canny instead of zero threshold level.
			// Canny helps to catch squares with gradient shading
			if (l == 0)
			{
				// apply Canny. Take the upper threshold from slider
				// and set the lower to 0 (which forces edges merging)
				Canny(gray0, gray, 0, thresh, 5);
				// dilate canny output to remove potential
				// holes between edge segments
				dilate(gray, gray, Mat(), Point(-1, -1));
			}
			else
			{
				// apply threshold if l!=0:
				//     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
				gray = gray0 >= (l + 1) * 255 / N;
			}

			// find contours and store them all as a list
			findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

			vector<Point> approx;

			// test each contour
			for (size_t i = 0; i < contours.size(); i++)
			{
				// approximate contour with accuracy proportional
				// to the contour perimeter
				approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

				// square contours should have 4 vertices after approximation
				// relatively large area (to filter out noisy contours)
				// and be convex.
				// Note: absolute value of an area is used because
				// area may be positive or negative - in accordance with the
				// contour orientation
				if (approx.size() == 4 &&
					fabs(contourArea(Mat(approx))) > 1000 &&
					isContourConvex(Mat(approx)))
				{
					double maxCosine = 0;

					for (int j = 2; j < 5; j++)
					{
						// find the maximum cosine of the angle between joint edges
						double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
						maxCosine = MAX(maxCosine, cosine);
					}

					// if cosines of all angles are small
					// (all angles are ~90 degree) then write quandrange
					// vertices to resultant sequence
					if (maxCosine < 0.3)
						squares.push_back(approx);
				}
			}
		}
	}
}

void organisePoints(const vector<vector<Point>> &squares) {
	Point temp;
	int quantity = 4;
	wektorX[0][0] = squares[1][0].x;
	wektorX[0][1] = squares[1][0].y;
	wektorX[1][0] = squares[1][1].x;
	wektorX[1][1] = squares[1][1].y;
	wektorX[2][0] = squares[1][2].x;
	wektorX[2][1] = squares[1][2].y;
	wektorX[3][0] = squares[1][3].x;
	wektorX[3][1] = squares[1][3].y;



	for (int i = 0; i < quantity - 1; i++) {
		for (int j = 0; j < quantity - 1 - i; j++) {
			if (wektorX[j][0] > wektorX[j + 1][0]) {
				temp = wektorX[j + 1][0];
				wektorX[j + 1][0] = wektorX[j][0];
				wektorX[j][0] = temp;
			}
		}
	}

	if (wektorX[0].y > wektorX[1].y) {
		temp = wektorX[1];
		wektorX[1] = wektorX[0];
		wektorX[0] = temp;
	}

	if (wektorX[2].y > wektorX[3].y) {
		temp = wektorX[3];
		wektorX[3] = wektorX[2];
		wektorX[2] = temp;
	}

}



//Przerobic na funkcje przyjmujaca 3 punkty i zwracaj¹ca index


//	(d/D)*3
//	d - odleglosc punktu testowyPunkcik od poczatku
//	D - szerokosc ramki
// tak samo z wysokoscia (d/D)*4
//Dodac rozciaganie ramki z 4 punktow nie z dwoch ;)
//Zapisanie sciezek audio w tablicy

Point poprzedniPunkt(0,0);

static int sprawdzamPoprzedni(const vector<vector<Point> >& squares, int szynaczy, int wynary) {
	int zwracana;
	if (poprzedniPunkt.x < squares[1][0].x && poprzedniPunkt.x > squares[1][0].x - szynaczy) {
		if (poprzedniPunkt.y > squares[1][0].y && poprzedniPunkt.y < squares[1][0].y + wynary) {
			//cout << "TRZECI KWADRAT" << endl;
			zwracana = 3;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + wynary && poprzedniPunkt.y < squares[1][0].y + (2 * wynary)) {
			//cout << "SZOSTY KWADRAT" << endl;
			zwracana = 6;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 2 * wynary && poprzedniPunkt.y < squares[1][0].y + (3 * wynary)) {
			//cout << "DZIEWIATY KWADRAT" << endl;
			zwracana = 9;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 3 * wynary && poprzedniPunkt.y < squares[1][0].y + (4 * wynary)) {
			//cout << "DWUNASTY KWADRAT" << endl;
			zwracana = 12;
			return zwracana;
		}

	}
	else if (poprzedniPunkt.x < squares[1][0].x + szynaczy && poprzedniPunkt.x > squares[1][0].x - (2 * szynaczy)) {
		if (poprzedniPunkt.y > squares[1][0].y && poprzedniPunkt.y < squares[1][0].y + wynary) {
			//cout << "DRUGI KWADRAT" << endl;
			zwracana = 2;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + wynary && poprzedniPunkt.y < squares[1][0].y + (2 * wynary)) {
			//cout << "PIATY KWADRAT" << endl;
			zwracana = 5;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 2 * wynary && poprzedniPunkt.y < squares[1][0].y + (3 * wynary)) {
			//cout << "OSMY KWADRAT" << endl;
			zwracana = 8;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 3 * wynary && poprzedniPunkt.y < squares[1][0].y + (4 * wynary)) {
			//cout << "JEDENASTY KWADRAT" << endl;
			zwracana = 11;
			return zwracana;
		}
	}
	else if (poprzedniPunkt.x < squares[1][0].x + (2 * szynaczy) && poprzedniPunkt.x > squares[1][0].x - (3 * szynaczy)) {
		if (poprzedniPunkt.y > squares[1][0].y && poprzedniPunkt.y < squares[1][0].y + wynary) {
			//cout << "PIERWSZY KWADRAT" << endl;
			zwracana = 1;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + wynary && poprzedniPunkt.y < squares[1][0].y + (2 * wynary)) {
			//cout << "CZWARTY KWADRAT" << endl;
			zwracana = 4;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 2 * wynary && poprzedniPunkt.y < squares[1][0].y + (3 * wynary)) {
			//cout << "SIODMY KWADRAT" << endl;
			zwracana = 7;
			return zwracana;
		}
		else if (poprzedniPunkt.y > squares[1][0].y + 3 * wynary && poprzedniPunkt.y < squares[1][0].y + (4 * wynary)) {
			//cout << "DZIESIATY KWADRAT" << endl;
			zwracana = 10;
			return zwracana;
		}
	}
	else {
		return -1;
	}

}



static void playSound(const vector<vector<Point> >& squares, Point testowyPunkcik) {
	
	

	if (testowyPunkcik.x < squares[1][0].x && testowyPunkcik.x > squares[1][0].x - szynaczy) {
		if (testowyPunkcik.y > squares[1][0].y && testowyPunkcik.y < squares[1][0].y + wynary) {		
			if (3 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "TRZECI KWADRAT" << endl;
				PlaySound(TEXT("testSounds/3.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + wynary && testowyPunkcik.y < squares[1][0].y + (2 * wynary)) {
			if (6 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "SZOSTY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/6.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 2 * wynary && testowyPunkcik.y < squares[1][0].y + (3 * wynary)) {
			if (9 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "DZIEWIATY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/9.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 3 * wynary && testowyPunkcik.y < squares[1][0].y + (4 * wynary)) {
			if (12 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "DWUNASTY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/12.wav"), NULL, SND_ASYNC);
			}
		}
	}
	else if (testowyPunkcik.x < squares[1][0].x + szynaczy && testowyPunkcik.x > squares[1][0].x - (2 * szynaczy)) {
		if (testowyPunkcik.y > squares[1][0].y && testowyPunkcik.y < squares[1][0].y + wynary) {
			if (2 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "DRUGI KWADRAT" << endl;
				PlaySound(TEXT("testSounds/2.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + wynary && testowyPunkcik.y < squares[1][0].y + (2 * wynary)) {
			if (5 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "PIATY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/5.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 2 * wynary && testowyPunkcik.y < squares[1][0].y + (3 * wynary)) {
			if (8 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "OSMY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/8.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 3 * wynary && testowyPunkcik.y < squares[1][0].y + (4 * wynary)) {
			if (11 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "JEDENASTY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/11.wav"), NULL, SND_ASYNC);
			}
		}
	}
	else if (testowyPunkcik.x < squares[1][0].x + (2 * szynaczy) && testowyPunkcik.x > squares[1][0].x - (3 * szynaczy)) {
		if (testowyPunkcik.y > squares[1][0].y && testowyPunkcik.y < squares[1][0].y + wynary) {
			if (1 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "PIERWSZY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/1.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + wynary && testowyPunkcik.y < squares[1][0].y + (2 * wynary)) {
			if (4 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "CZWARTY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/4.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 2 * wynary && testowyPunkcik.y < squares[1][0].y + (3 * wynary)) {
			if (7 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "SIODMY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/7.wav"), NULL, SND_ASYNC);
			}
		}
		else if (testowyPunkcik.y > squares[1][0].y + 3 * wynary && testowyPunkcik.y < squares[1][0].y + (4 * wynary)) {
			if (10 == sprawdzamPoprzedni(squares, szynaczy, wynary)) {
			}
			else {
				cout << "DZIESIATY KWADRAT" << endl;
				PlaySound(TEXT("testSounds/10.wav"), NULL, SND_ASYNC);
			}
		}
	}
	else {
	}

	poprzedniPunkt.x = testowyPunkcik.x;
	poprzedniPunkt.y = testowyPunkcik.y;
}

void drawSquares(const vector<vector<Point> >& squares, Mat image_) {
	const Point* p = &squares[1][0];
	int n = (int)squares[1].size();
	if (p->x > 3 && p->y > 3)
		polylines(image_, &p, &n, 1, true, Scalar(0, 255, 0), 3, LINE_AA);
	FRAME_HEIGHT = abs(squares[1][0].y - squares[4][2].y);
	FRAME_WIDTH = abs(squares[4][2].x - squares[1][0].x);
	//Rect rectangle = Rect(squares[1][0].x, squares[1][0].y, szerokosc, wysokosc);
	//Mat croppedImage = image_(rectangle);
	imshow(wndname, image_);
	//return image_;
}




int main(int argc, char** argv) {

	unsigned char znak;
	
	vector<vector<Point> > squares;
	Mat image;
	Point p;
	Mat imgOriginal;



	cout << "Wciœnij ENTER, aby skalibrowaæ aplikacje..." << endl;
		
		namedWindow(wndname, 1);

		/**********************************************************************************************************************************/
		/**********************************************************************************************************************************/
		/**********************************************************************************************************************************/
		/*MOZECIE KORZYSTAC Z PROGRAMU PRZEZ WYKOMENTOWANIE FRAMEFINDERA(). MUSICIE TYLKO MIEC ZDJECIE BINARNE RAMKI W FOLDERZE ***********/
		/*testImages/PrototypeImages/1.jpg ************************************************************************************************/
		/**********************************************************************************************************************************/
		/**********************************************************************************************************************************/
		/**********************************************************************************************************************************/

		//frameFinder();
		
	image = imread("testImages/PrototypeImages/1.jpg", 1);
	if (image.empty()) {
		cout << "error: image not read from file\n\n";
		system("PAUSE");
	}
	try {

		findSquares(image, squares);
		drawSquares(squares, image);
	}
	catch (Exception e)	{
		cout << e.code<< endl;
	}
	waitKey(30);

	VideoCapture vCapture;
	vCapture.open(0);
	vCapture.set(CV_CAP_PROP_FRAME_WIDTH, WINDOW_WIDTH);
	vCapture.set(CV_CAP_PROP_FRAME_HEIGHT, WINDOW_HEIGHT);
	waitKey(30);

	organisePoints(squares);

	/*for (int i = 0; i < 4; i++) {
		cout << wektorX[i] << endl;
	}
	*/
	/*
	while (1) {

		vCapture.read(imgOriginal);
		
		resize(imgOriginal, imgOriginal, Size(WINDOW_WIDTH, WINDOW_HEIGHT));
		imgOriginal = drawGrid(imgOriginal, squares);
		waitKey(30);
		imshow("ABCORIGINAL", imgOriginal);
		//p = flashFinder(imgOriginal,squares);
		//playSound(squares, p);
	}
	*/
	return 0;
}
