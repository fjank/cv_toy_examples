#include "SaliencyCut.h"

void setMaskBorder(Mat &mask, int borderWidth = 15){
	Rect rect(borderWidth, borderWidth, mask.size().width-borderWidth*2, mask.size().height-borderWidth*2);
	Mat tmp(mask.size(), CV_8UC1, 1);
	tmp(rect) = 0;
	mask.setTo(GC_BGD, tmp);
	//imshow("roi", mask);
}

void saliencyCut(Mat im, Mat salim, Mat &outim, bool intermediate, int thres, int maxIter, int borderWidth){
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

	//dilation和erosion的kernel的定义
	Mat dilation_dst;
	int dilation_type = MORPH_RECT;
	int dilation_size = 3;
	Mat d_element = getStructuringElement( dilation_type,
		Size( 2*dilation_size + 1, 2*dilation_size+1 ),
		Point( dilation_size, dilation_size ) );
	Mat erosion_dst;
	int erosion_type = MORPH_RECT;
	int erosion_size = 3;
	Mat e_element = getStructuringElement( erosion_type,
		Size( 2*erosion_size + 1, 2*erosion_size+1 ),
		Point( erosion_size, erosion_size ) );
	
	//进行迭代
	int iter = 0;
	while (iter++<maxIter){
		//dilation
		dilate( outim, dilation_dst, d_element );
		//imshow( "Dilation Demo", dilation_dst );

		//erosion	
		erode( outim, erosion_dst, e_element );
		//imshow( "Erosion Demo", erosion_dst );

		//设置grabcut新的mask
		mask.setTo(GC_PR_FGD);//过渡像素设置为可能的前景
		mask.setTo(GC_BGD, dilation_dst<128);//膨胀后的背景像素是mask的背景
		mask.setTo(GC_FGD, erosion_dst >= 128);//腐蚀后的前景是mask的前景
		setMaskBorder(mask, borderWidth);//设置背景边框
		//imshow("mask", mask);

		//使用grabcut
		grabCut(im, mask, rect, bgdmodel, fgdmodel, 1, GC_INIT_WITH_MASK);

		//设置输出图片
		outim.setTo(0);
		outim.setTo(255, mask);

		//输出中间结果
		if (intermediate){
			char outimname[20];
			sprintf(outimname, "iter%d.jpg", iter);
			imwrite(outimname, outim);
		}
		
	}

}


