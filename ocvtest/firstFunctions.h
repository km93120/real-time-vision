#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define GAUSSIAN_BLUR 0
#define MEDIAN_BLUR 1
#define BILATERAL_BLUR 2

#define DILATING	3
#define ERODING		4

#define LAPLACIAN 5
#define SCALING 6 
#define CANNY 7 


void imageSmoothing(Mat srcImg, Mat &outputImg, Size kernelSize, int type)
{
	switch (type)
	{
	case 0:
		GaussianBlur(srcImg, outputImg, kernelSize, 0.0);
		break;
	case 1:
		medianBlur(srcImg, outputImg, kernelSize.height);
		break;
	case 2:
		bilateralFilter(srcImg, outputImg, 15, 30, 7.5);
		break;

	}
}

void mathematicalMorphology(Mat	srcImg, Mat &outputImg, int operationType, Mat structuringElement)
{
	switch (operationType)
	{
	case 3:
		dilate(srcImg, outputImg, structuringElement);
		break;
	case 4:
		erode(srcImg, outputImg, structuringElement);
		break;
	}

}

void imageThresholding(Mat srcImg, Mat &outputImg, int minThreshold, int maxThreshold)
{
	threshold(srcImg, outputImg, minThreshold, maxThreshold, 1);

}

void contoursDetection(Mat srcImg, Mat &outputImg, int operationType)
{
	switch (operationType)
	{
	case 5:

		break;
	case 6:

		break;
	case 7:

		break;

	}
}

void imageMatching(Mat srcImg, Mat &dst, Mat templateImg)
{
	matchTemplate(srcImg, templateImg, dst, TM_SQDIFF_NORMED);
}

void cannyEdgeDetection(Mat srcImg, Mat &outputImg, Mat dest, int minThreshold, int maxThreshold, void*)
{

	Canny(srcImg, outputImg, minThreshold, maxThreshold);


}

void hull()
{
	int imageRows = 500;
	int imageColumns = 500;

	int minY = imageRows * 0.25;
	int maxY = imageRows * 0.75;

	int minX = imageColumns * 0.25;
	int maxX = imageColumns * 0.75;


	vector < Point > points;
	Mat srcImg = imread("images/porsche.jpg");
	Mat img = Mat::zeros(imageRows, imageColumns, CV_32F);
	for (int i = 0; i < 1000; i++)
	{


		int rngX = rand() % (maxX - minX + 1) + minX;
		int rngY = rand() % (maxY - minY + 1) + minY;
		Point point(rngX, rngY);
		points.push_back(point);
		circle(img, point, 1, Scalar(255.0));



	}

	vector<vector< Point > > hull(points.size());

	convexHull(points, hull);

	if (hull.empty())
	{
		cout << "error when loading file";

	}
	drawContours(img, hull, 1, Scalar(255.0, 255.0, 255.0, 255.0));

	Mat outputImg;


	/*if (srcImg.data == NULL)
	{
		cout << "error when loading file";
		return -1;
	}*/


	rectangle(img, Point(minX, minY), Point(maxX, maxY), Scalar(255.0, 255.0, 255.0, 1.0));
	imshow("result", img);

}