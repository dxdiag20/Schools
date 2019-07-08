#include "opencv2\opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(){

	Mat src, YCrCbMat, OpenCV_YCrCbMat;

	src = imread("lena_color.jpg",CV_LOAD_IMAGE_COLOR);

	if(src.empty()){
		std::cout << "������ �����ϴ�. " << std::endl;
		return -1;
	}
	
	YCrCbMat.create(Size(src.rows, src.cols), CV_8UC3);
	
	//BGR -> YCrCb�� �����Ͻÿ�.
	for(int j=0; j<src.rows;j++){
		for(int i=0;i<src.cols;i++){
			float B = src.at<Vec3b>(j,i)[0];
			float G = src.at<Vec3b>(j,i)[1];
			float R = src.at<Vec3b>(j,i)[2];
			YCrCbMat.at<Vec3b>(j,i)[0] = 0 + 0.299*R+0.587*G+0.114*B;
			YCrCbMat.at<Vec3b>(j,i)[1] = 128 +0.5*R-0.419*G-0.081*B;
			YCrCbMat.at<Vec3b>(j,i)[2] = 128 -0.169*R-0.331*G+0.5*G;
		}
	}

	//OpenCV �Լ��� ����� BGR -> YCrCb
	cvtColor(src, OpenCV_YCrCbMat, CV_BGR2YCrCb);

	imshow("original", src);
	imshow("YCrCb", YCrCbMat);
	imshow("OpenCV_YCrCb", OpenCV_YCrCbMat);
	cvWaitKey();
}