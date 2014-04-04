#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

int main(){
	Mat im;
	im = imread("lena.jpg");
	//imshow("lena", im);
	
	Mat mask, bgdmodel, fgdmodel;
	Mat res(im.size(), CV_8UC1, Scalar(0));//��������ͼƬ
	//res.create(im.size(), CV_8UC1, Scalar(0));//����������ȼ�

	//Grabcut��rect������Ϊͼ�����һ����СΪԭͼ1/4�ľ��Ρ�
	int width = im.size().width;
	int height = im.size().height;
	int x1 = width/4;
	int y1 = height/4;
	int x2 = width/4*3;
	int y2 = height/4*3;
	Rect rect(Point(x1, y1), Point(x2, y2));

	//GrabCut��mask�����ﲻ�����ã���Ϊgrabcut��������ΪGC_INIT_WITH_RECT
	mask.create(im.size(), CV_8UC1);
	mask.setTo(GC_BGD);
	(mask(rect)).setTo(Scalar(GC_PR_FGD));
	
	//��GC_INIT_WITH_RECTʱ��Rect�м���GC_PR_FGD������������GC_BGD
	grabCut(im, mask, rect, bgdmodel, fgdmodel, 1, GC_INIT_WITH_RECT);

	res.setTo(255, mask&1);
	imwrite("result1.jpg", res);
	
	//ע�⵽copyTo����������Ӧ�ԣ�res�����ǵ�ͨ���ģ�copyTo֮�����˺�imһ����3ͨ��
	im.copyTo(res, mask&1);
	imwrite("result2.jpg", res);

	imshow("res", res);
	waitKey(0);
	return 0;
}
