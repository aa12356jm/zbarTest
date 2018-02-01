#pragma once

#include <string>
#include "opencv/cv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "ZBar/include/zbar.h" 
#include "iconv/include/iconv.h"

using namespace cv;
using namespace std;
using namespace zbar;

class  BarcodeDetect
{
public:
	BarcodeDetect();
	~BarcodeDetect();

	bool detectBarcode(cv::Mat img, std::string& SN);
	bool detectBarcode(const string filename, vector<string> &SN);
	bool detectBarcode(const string filename, string &SN);

	bool detectBarcode(cv::Mat img, vector<string> &SN);

};
