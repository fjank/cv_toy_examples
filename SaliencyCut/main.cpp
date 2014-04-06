#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "SaliencyCut.h"
using namespace std;
using namespace cv;

int main(){
	Mat im, salim, outim;
	im = imread("lena.jpg");
	salim = imread("lena_HC.png", IMREAD_GRAYSCALE);
	saliencyCut(im, salim, outim, true);
	//imshow("result", outim);
	imwrite("lena.out.png", outim);
	//waitKey(0);
	return 0;
}