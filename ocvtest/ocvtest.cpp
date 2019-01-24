// ocvtest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define GAUSSIAN_BLUR 0
#define MEDIAN_BLUR 1
#define BILATERAL_BLUR 2

#define DILATING	3
#define ERODING		4


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
		dilate(srcImg,outputImg,structuringElement);
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

// morphology : dilatation : /!\
					//	    /___\
 
int main()
{
	
	Mat srcImg = imread("images/tiger.jpg");
	Mat gray; 
	cvtColor(srcImg, srcImg, cv::COLOR_RGB2GRAY);
	Mat outputImg,outputImg1;
	//Mat outputImg0, outputImg1, outputImg2 ;
	Mat kernel;
	int kernelSize = 7;

	
	imageThresholding(srcImg, outputImg, 100, 255);

	if (srcImg.data == NULL)
	{
		cout << "error when loading file"; 
		return -1;
	}

	imshow("originalImage", outputImg);

	waitKey(-1);
	return 0;
}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5.  Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.


