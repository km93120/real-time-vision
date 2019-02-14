#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat & colorThresholding(Mat &srcImg)
{
	Scalar lowerBound = Scalar(0, 39, 68 );
	Scalar upperBound = Scalar(10, 69, 100);

	inRange(srcImg, Scalar(170, 160, 60), Scalar(180, 255, 255),srcImg);
	
	return srcImg;
}

Mat & closingContours(Mat &srcImg)
{
	Mat structuringElement = getStructuringElement(MORPH_RECT, Size(7, 7), Point(3, 3));
	morphologyEx(srcImg, srcImg, MORPH_CLOSE, structuringElement);
	return srcImg;
}

Mat & cannyEdgeDetection(Mat &srcImg,int minThreshold, int maxThreshold)
{

	Canny(srcImg, srcImg, minThreshold, maxThreshold);
	return srcImg;

}

Mat & dilateImg(Mat &srcImg)
{
	Mat structuringElement = getStructuringElement(MORPH_RECT, Size(7, 7), Point(3, 3));
	morphologyEx(srcImg, srcImg, MORPH_DILATE, structuringElement);
	return srcImg;
}

Mat & findAndTraceContours(Mat &srcImg)
{
	/*const static Scalar colors[] =
	{
		Scalar(255,0,0),
		Scalar(255,128,0),
		Scalar(255,255,0),
		Scalar(0,255,0),
		Scalar(0,128,255),
		Scalar(0,255,255),
		Scalar(0,0,255),
		Scalar(255,0,255)
	};*/
	//Scalar color = colors[rand() % 8];
	vector<vector<Point>> contours;
	findContours(srcImg, contours, RETR_EXTERNAL, CHAIN_APPROX_TC89_L1);
	drawContours(srcImg, contours, -1, Scalar(125,125, 0) );
	return srcImg;
}

Mat & thresholdingBySurface(Mat & img)
{
	int imgRows, imgCols,imgType;
	imgRows = img.rows;
	imgCols = img.cols;
	//imgType = img.type;
	//cout << imgType;
	vector<vector<Point>> contours;
	vector<vector<Point>> slctedContours;
	Mat filteredImg = Mat(imgRows, imgCols, CV_16F);


	findContours(img, contours, RETR_EXTERNAL, CHAIN_APPROX_TC89_L1);
	for (vector<vector<Point >>::iterator it = contours.begin(); it != contours.end(); ++it)
	{
		if (contourArea(*it) > 500)
		{
			slctedContours.push_back(*it);
		}

	}
	drawContours(img, slctedContours, -1, Scalar(125, 125, 0));
	return img;
}
