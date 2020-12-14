//
// Created by imcaimca on 2020/11/5.
//

#ifndef QR_DISCRIMINATE_H
#define QR_DISCRIMINATE_H
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/types_c.h>
#include <wiringPi.h>
#include <wiringSerial.h>
using namespace std;
using namespace cv;

#define MVCAMERA_HEIGHT_PIX 0.00468
#define ARMOR_HEIGHT 58  //57
#define LENS_FOCAL 8

class Discriminate {
public:
    void QrCode(Mat img, std::string & str);
    void processing(Mat imgOriginal, Mat & imgThresholded, vector<vector<Point> > & contours, Scalar scalarLow, Scalar scalarHigh);
    void drawing(Mat & imgOriginal, vector<vector<Point> > contours, string str);
    bool trafficLights(Mat & img);
    int serialSend1(string ss);
};


#endif //QR_DISCRIMINATE_H
