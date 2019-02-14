// ocvtest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <opencv2/opencv.hpp>
#include "colorSegmentation.h"
#include <iostream>

using namespace std;
using namespace cv;

// morphology : dilatation : /!\
					//	    /___\
 
int main()
{
	VideoCapture cap("vid1.MOV");

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	Scalar color;
	while (1) {

		Mat frame,hsvFrame;
		cap >> frame;

		resize(frame, frame, Size(340, 480), 0.0, 0.0, INTER_LINEAR);
		cvtColor(frame, hsvFrame, COLOR_BGR2HSV);

		int minThreshold, maxThreshold;
		minThreshold = 100;
		maxThreshold = 200;

		//red : 353 -> 6
		if (frame.empty())
		{
			return -1;
		}
			
		imshow("thresholded Frame(1)", colorThresholding(hsvFrame));
		imshow("closed frame(2)", closingContours(hsvFrame));
		imshow("canny edge detection(3)", cannyEdgeDetection(hsvFrame, minThreshold, maxThreshold));
		imshow("dilated frame(4)", dilateImg(hsvFrame));
		Mat dilated = hsvFrame.clone();
		imshow("contours(5)", findAndTraceContours(hsvFrame));
		imshow("filtered areas(6)", thresholdingBySurface(dilated));
		imshow("original frame", frame);

		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}
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


