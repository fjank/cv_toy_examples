#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

int main(){
	Mat im;
	im = imread("lena.jpg");
	imshow("luna", im);
	waitKey(0);
	return 0;
}

