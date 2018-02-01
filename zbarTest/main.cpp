#include"BarcodeDetect.h"

int main()
{
	BarcodeDetect barCodeDetect;
	Mat BarCodeRoi = imread("222.png");
	string sn;
	barCodeDetect.detectBarcode(BarCodeRoi, sn);

	return 0;
}