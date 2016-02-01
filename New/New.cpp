// 

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>

//using namespace cv;
//using namespace std;

int main(){

	cv::Mat image;
	image = cv::imread("../image/test.jpg");   // Read the file
	uchar *pixptr;
	double a;		//for determine the dark side
	double b;
	int type;
	double level;

	std::cout << "type(cold:1,warm:2):";
	std::cin >> type;
	std::cout << "level(1~5):";
	std::cin >> level;

	level = level / 10;
	a = 1 + level;
	b = 1 - level;

	if(image.empty()){
		std::cout << "image missing";
		system ("pause");
		return 0;
	}
	for(int i=0; i<image.rows; i++){
		pixptr = image.ptr<uchar>(i);
		for(int j=0; j<image.cols; j++){
			
			if (type == 1){
				pixptr[2] = pixptr[2] * b;

				if ((pixptr[1] * a)>255) pixptr[1] = 255;
				else pixptr[1] = pixptr[1] * a;

				if ((pixptr[0] * a)>255) pixptr[0] = 255;
				else pixptr[0] = pixptr[0] * a;
			}

			else if (type == 2){
				if ((pixptr[2] * a) > 255) pixptr[2] = 255;
				else pixptr[2] = pixptr[2] * a;

				if ((pixptr[1] * a) > 255) pixptr[1] = 255;
				else pixptr[1] = pixptr[1] * a;

				pixptr[0] = pixptr[0] * b;
			}
			pixptr+=3;
		}
	}
	cv::imwrite("../image/Result_test_2.png", image);
	cv::imshow("Traverse result", image);
    cv::waitKey(0);
	return(0);
}