//
// Created by imcaimca on 2020/11/5.
//

#include "Discriminate.h"

void Discriminate::processing(Mat imgOriginal, Mat &imgThresholded, vector<vector<Point> > &contours, Scalar scalarLow,
                              Scalar scalarHigh)
{
    Mat imgHSV;
    vector<Mat> hsvSplit;
    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    split(imgHSV, hsvSplit);
    equalizeHist(hsvSplit[2],hsvSplit[2]);
    merge(hsvSplit,imgHSV);

    inRange(imgHSV, scalarLow, scalarHigh, imgThresholded);

    //开操作 (去除一些噪点)
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

    //闭操作 (连接一些连通域)
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

    vector<Vec4i> hierarchy;
    findContours( imgThresholded, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
}

float calculateCircularity(vector<Point> contours)
{
	Point2f center;
	float radius = 0;
	minEnclosingCircle((Mat)contours, center, radius);
	float fsum = 0;
	float fcompare = 0;
	for (int i = 0; i < contours.size(); i++)
	{
		Point2f ptmp = contours[i];
		//计算距离
		float fdistance = sqrt(((float)ptmp.x - center.x)*((float)ptmp.x - center.x) + ((float)ptmp.y - center.y)*((float)ptmp.y - center.y));
        //累加距离到圆心的差值
		float fdiff = abs(fdistance - radius);
		fsum = fsum + fdiff;
	}
	fcompare = fsum / (float)contours.size();
	return fcompare;
}

void Discriminate::drawing(Mat &imgOriginal, vector<vector<Point> > contours, string str)
{
    /*vector<Moments> mu(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mu[i] = moments(contours[i], false);
    }
    ///  计算矩中心:
    vector<Point2f> mc(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
    }*/
    vector<Point2f>center( contours.size() );
    vector<float>radius( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {
        float fCircle = calculateCircularity(contours[i]);
        double area = contourArea(contours[i]);
        cout << area << endl;
        if(fCircle > 0.6 && area < 200 && area > 100) continue;
        //boundRect[i] = boundingRect( Mat(contours[i]) );
        //RotatedRect rectElli = fitEllipse(vfindContours);
        //float fR = MIN(rectElli.size.width , rectElli.size.height);// 是否为圆，可以比较这两个值，若十分接近或相等，就是一个正圆
        //cout << "fitEllipse 中心: " <<  rectElli.center.x << ", " <<rectElli.center.y << "  半径:"<<fR/2<< endl;  
        //circle(q_MatImageShow, Point(rectElli.center), fR/2, Scalar(0,0,255), 2);//圆周

        minEnclosingCircle( contours[i], center[i], radius[i] );
        if(radius[i] > 50)
        { 
            Scalar color = Scalar(255);
            circle(imgOriginal, center[i], radius[i], color, -1, 8, 0);
            putText(imgOriginal, str, center[i],FONT_HERSHEY_COMPLEX,1,color, 2, 8);
        }
    }
    /*for (int i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(255);
        circle(imgOriginal, center[i], radius[i], color, -1, 8, 0);
        putText(imgOriginal, str, center[i],FONT_HERSHEY_COMPLEX,1,color, 2, 8);
    }*/
}

bool Discriminate::trafficLights(Mat &img)
{
       Mat imgThresholded_r, imgThresholded_g, imgThresholded_y;
       Mat bgr_image;
       img.copyTo(bgr_image);

       cv::Mat hsv_image;
       cv::cvtColor(bgr_image, hsv_image, cv::COLOR_BGR2HSV);
       // Threshold the HSV image, keep only the red pixels
       cv::Mat lower_red_hue_range;
       cv::Mat upper_red_hue_range;
       //cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lower_red_hue_range);
       //cv::inRange(hsv_image, cv::Scalar(150, 100, 100), cv::Scalar(179, 255, 255), upper_red_hue_range);
       //cv::inRange(hsv_image, cv::Scalar(20, 100, 100), cv::Scalar(21, 255, 255), lower_red_hue_range);
       cv::inRange(hsv_image, cv::Scalar(35, 120, 100), cv::Scalar(77, 255, 255), upper_red_hue_range);
       cv::Mat red_hue_image;
       //cv::addWeighted(lower_red_hue_range, 1.0, upper_red_hue_range, 1.0, 0.0, red_hue_image);
//     imshow("lower_red_hue_range",lower_red_hue_range);
	   imshow("upper_red_hue_range",upper_red_hue_range);
//     imshow("red_hue_image",red_hue_image);
       cv::GaussianBlur(upper_red_hue_range, red_hue_image, cv::Size(9, 9), 2, 2);
       std::vector<cv::Vec3f> circles;
       cv::HoughCircles(red_hue_image, circles, CV_HOUGH_GRADIENT, 1, red_hue_image.rows / 8, 100, 20, 0, 0);
       //if (circles.size() == 0) std::exit(-1);
       for (size_t current_circle = 0; current_circle < circles.size(); ++current_circle) {
           cv::Point center(std::round(circles[current_circle][0]), std::round(circles[current_circle][1]));
           int radius = std::round(circles[current_circle][2]);
           cv::circle(img, center, radius, cv::Scalar(0, 255, 0), 5);
       }
       imshow("Original", img);
	   if (circles.size() != 0) return true;
	   return false;
}

void Discriminate::QrCode(Mat img, std::string &str)
{
    QRCodeDetector QRdetecter;
    vector<cv::Point> list;
    Mat res;
    QRdetecter.detectAndDecode(img, list, res);
    str= QRdetecter.detectAndDecode(img, list, res);
    cout << str << std::endl;
    for (int i = 0; i < list.size(); i++) {

        if (i == 3)
            line(img, list[i], list[0], Scalar(0, 255, 0), 2);
        else
            line(img, list[i], list[i + 1], Scalar(0, 255, 0), 2);

    }
    putText(img,str, Point(img.cols / 2, img.rows/ 2),FONT_HERSHEY_COMPLEX,2,Scalar(0, 0, 255), 3, 8);
    imshow("测试窗口", img);
}


int Discriminate::serialSend1(string ss)
{
    int fd;
	if(wiringPiSetup()<0)
		return 1;
	if((fd=serialOpen("/dev/MYUSB",115200))<0)
		return 1;
	printf("serial test start ...\n");
    if(ss=="11")
        serialPuts(fd, "1");
    else if(ss=="12")
        serialPuts(fd, "2");
    else if(ss=="21")
        serialPuts(fd, "3");
    else if(ss=="22")
        serialPuts(fd, "4");
	serialClose(fd);
	return 0;
} 
