#include <iostream>
#include "cv.h"
#include "highgui.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(){

	string dir_path = "./";
	string out_path = "./";
	Directory dir; 
	vector<string> fileNames = dir.GetListFiles(dir_path, "*.jpg", false ); 

	for(int i=0; i < fileNames.size(); i++) {
		string fileName = fileNames[i];
		string fid = fileName.substr(0, fileName.length()-4);
		string fileFullName = dir_path + fileName; 

		Mat im;
		im = imread(fileFullName);
		//imshow("lena", im);

		Mat mask, bgdmodel, fgdmodel;
		Mat res(im.size(), CV_8UC1, Scalar(0));//存放输出的图片
		//res.create(im.size(), CV_8UC1, Scalar(0));//与上面的语句等价

		//Grabcut的rect，设置为图中央的一个大小为原图1/4的矩形。
		int width = im.size().width;
		int height = im.size().height;
		int x1 = width/4;
		int y1 = height/4;
		int x2 = width/4*3;
		int y2 = height/4*3;
		Rect rect(Point(x1, y1), Point(x2, y2));

		//GrabCut的mask，这里不起作用，因为grabcut参数设置为GC_INIT_WITH_RECT
		mask.create(im.size(), CV_8UC1);
		mask.setTo(GC_BGD);
		(mask(rect)).setTo(Scalar(GC_PR_FGD));

		//用GC_INIT_WITH_RECT时候，Rect中间是GC_PR_FGD，矩形外面是GC_BGD
		grabCut(im, mask, rect, bgdmodel, fgdmodel, 1, GC_INIT_WITH_RECT);

		res.setTo(255, mask&1);
		imwrite(out_path+fid+"_result1.jpg", res);

		//注意到copyTo函数的自适应性，res本来是单通道的，copyTo之后变成了和im一样的3通道
		im.copyTo(res, mask&1);
		imwrite(out_path+fid+"_result2.jpg", res);

		imshow("res", res);
		//waitKey(0);
	}


	return 0;
}
