#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

void setMaskBorder(Mat &mask, int borderWidth = 15){
	Rect rect(borderWidth, borderWidth, mask.size().width-borderWidth*2, mask.size().height-borderWidth*2);
	Mat tmp(mask.size(), CV_8UC1, 1);
	tmp(rect) = 0;
	mask.setTo(GC_BGD, tmp);
	//imshow("roi", mask);
}

void saliencyCut(Mat im, Mat salim, Mat &outim, int thres = 70, int maxIter = 4, int borderWidth = 15){
	//salim.copyTo(outim);
	//根据thres来二值化图像
	threshold(salim, outim, thres, 255, CV_THRESH_BINARY);
	
	//初始化mask
	Mat mask(im.size(), CV_8UC1, Scalar(GC_BGD));
	mask.setTo(GC_PR_FGD, outim&1);
	setMaskBorder(mask, borderWidth);
	//imshow("mask", mask);
	//waitKey(0);

	//第一次grabcut
	Mat bgdmodel, fgdmodel;
	Rect rect;
	grabCut(im, mask, rect, bgdmodel, fgdmodel, 1, GC_INIT_WITH_MASK);

	outim.setTo(0);
	outim.setTo(255, mask);
}

int main(){
	Mat im, salim, outim;
	im = imread("lena.jpg");
	salim = imread("lena_HC.png", IMREAD_GRAYSCALE);
	saliencyCut(im, salim, outim);
	imshow("result", outim);
	imwrite("lena.out.png", outim);
	waitKey(0);
	return 0;
}
