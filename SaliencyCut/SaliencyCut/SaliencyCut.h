#include <iostream>
#include "cv.h"
#include "highgui.h"
using namespace std;
using namespace cv;

//************************************************************************/
//* im: ����ԭͼƬ
//* salim��saliency map
//* outim������Ľ��ͼƬ
//* intermediate���Ƿ�����м���ͼ
//* thres����ʼ��ʱ���ֵ������ֵ
//* maxIter��grabcut��������
//* borderWidth��grabcut��mask�ı����߿���*/
//************************************************************************//
void saliencyCut(Mat im, Mat salim, Mat &outim, bool intermediate = false, int thres = 70, int maxIter = 4, int borderWidth = 15);

