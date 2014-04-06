#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

//************************************************************************/
//* im: 输入原图片
//* salim：saliency map
//* outim：输出的结果图片
//* intermediate：是否输出中间结果图
//* thres：初始化时候二值化的阈值
//* maxIter：grabcut迭代次数
//* borderWidth：grabcut中mask的背景边框宽度*/
//************************************************************************//
void saliencyCut(Mat im, Mat salim, Mat &outim, bool intermediate = false, int thres = 70, int maxIter = 4, int borderWidth = 15);

