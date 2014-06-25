#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

int main(){
	Mat im;
	im = imread( "lena.jpg");
	int width = im.size().width;
	int height = im.size().height;
	int min_len = MIN(width, height);
	Mat crop_im=  im(Rect((width-min_len)/2, (height-min_len)/2, min_len, min_len));
	//Mat crop_im=  im(Rect(im.size().width / 4, im.size().height / 4, im.size().width / 2, im.size().height / 2));
	//Mat crop_im = im(Rect(100,100,300,300));
	imshow( "lena", crop_im);
	waitKey(0);
	return 0;
}
