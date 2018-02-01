#include "BarcodeDetect.h"


BarcodeDetect::BarcodeDetect()
{

}
BarcodeDetect::~BarcodeDetect()
{

}

bool BarcodeDetect::detectBarcode(const string filename,vector<string> &SN)
{
	Mat result = imread(filename);

	if (!result.empty())
	{
		//现在开始识别
		Mat grayImage;
		cvtColor(result, grayImage, CV_RGB2GRAY);
		int width = grayImage.cols;
		int height = grayImage.rows;
		Image image(width, height, "Y800", grayImage.data, width*height);
		ImageScanner scanner;
		scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
		int n = scanner.scan(image);//返回扫描到的条码的数量
		cout << "图片中条码数量为:" << n << endl;
		//循环打印图片中的所有条码信息
		Image::SymbolIterator symbol;

		for (symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
		{
			cout << "pic name:\t" << filename << endl << "code type:\t" << symbol->get_type_name() << endl << \
				"decode string:\t" << symbol->get_data() << endl;

			SN.push_back(symbol->get_data());
			image.set_data(NULL, 0);
		}
	}

	return true;
}

bool BarcodeDetect::detectBarcode(cv::Mat img, vector<string> &SN)
{
	assert(img.data != NULL);
	//现在开始识别
	Mat grayImage;
	cvtColor(img, grayImage, CV_RGB2GRAY);
	int width = grayImage.cols;
	int height = grayImage.rows;
	Image image(width, height, "Y800", grayImage.data, width*height);
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	int n = scanner.scan(image);//返回扫描到的条码的数量
	cout << "图片中条码数量为:" << n << endl;
	//循环打印图片中的所有条码信息
	Image::SymbolIterator symbol;

	for (symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
	{
		cout << "code type:\t" << symbol->get_type_name() << endl << \
			"decode string:\t" << symbol->get_data() << endl;
		SN.push_back(symbol->get_data());
		image.set_data(NULL, 0);
	}

	return true;
}

bool BarcodeDetect::detectBarcode(Mat img, string &SN)
{
	if (!img.empty())
	{
		//现在开始识别
		Mat grayImage;
		cvtColor(img, grayImage, CV_RGB2GRAY);
		int width = grayImage.cols;
		int height = grayImage.rows;
		Image image(width, height, "Y800", grayImage.data, width*height);
		ImageScanner scanner;
		scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
		int n = scanner.scan(image);//返回扫描到的条码的数量
		cout << "图片中条码数量为:" << n << endl;
		//循环打印图片中的所有条码信息
		Image::SymbolIterator symbol;

		for (symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
		{
			cout << "code type:\t" << symbol->get_type_name() << endl << \
				"decode string:\t" << symbol->get_data() << endl;
			SN = symbol->get_data();
			image.set_data(NULL, 0);
			return true;
		}
	}

	return false;
}


bool BarcodeDetect::detectBarcode(const string filename, string &SN)
{
	vector<string> sn;
	SN = "NotFound";
	bool ret = detectBarcode(filename, sn);
	
	if (!sn.empty())
	{
		SN = sn[0];
	}

	return ret;
}
