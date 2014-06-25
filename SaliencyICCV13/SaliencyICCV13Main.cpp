// SaliencyICCV13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "CmSaliencyGC.h"

int main(int argc, char* argv[])
{
	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_subTaobao/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_subTaobao/" ;

	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_CSSD/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_CSSD/" ;

	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_ECSSD/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_ECSSD/" ;

	CStr inDir = "D:/研究生阶段工作/201402 CNN/CNN分割结果的优化问题/20140417之后的优化工作/20140513 跑实验/data/" ;
	CStr outDir = "D:/研究生阶段工作/201402 CNN/CNN分割结果的优化问题/20140417之后的优化工作/20140513 跑实验/data/" ;

	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_SOD/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_SOD/" ;

	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_SED/1obj/color/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_SED/1obj/color/" ;

	//CStr inDir = "F:/Image DataSet/SaliencyImgs/Imgs_taobao/" ;
	//CStr outDir = "F:/Image DataSet/SaliencyImgs/Result_taobao/" ;

	//for ( int t = 0; t < 5; t++ )
		CmSaliencyGC::Demo( inDir, outDir ); // (un)comment `#define _GET_CSD' in "CmSaliencyGC.cpp":Line 3 for trade off between speed and accuracy

	return 0 ;
}

