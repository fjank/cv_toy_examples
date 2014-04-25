#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

int main(){
	Mat im;
	im = imread( "lena.jpg");
	imshow( "lena", im);
	waitKey(0);

	Size size = im.size();
	int height = size.height;
	int width = size.width;

	
	uchar* data = NULL;
	for (int h = 0; h < height; h++){
		for (int w = 0; w < width; w++){
			 data = im.data + h * im.step[0] + w * im.step[1];
			 data[0] = 255 - data[0];
			 data[1] = 255 - data[1];
			 data[2] = 255 - data[2];

		}
	}

	imshow( "lena", im);
	waitKey(0);



	return 0;
}
