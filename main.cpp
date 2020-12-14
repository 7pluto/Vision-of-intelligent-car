#include <iostream>
#include "Discriminate.h"

int main() {
    Discriminate dm;
    VideoCapture cap;
    cap.open(0);
    cap.set(CAP_PROP_FRAME_WIDTH, 20);//宽度 
    cap.set(CAP_PROP_FRAME_HEIGHT, 20);//高度
    cap.set(cv::CAP_PROP_FPS, 5);
    Mat img, image1, image2;
    std::string str, str2;
	int count = 0;
    while(1)
    {
        cap >> img;
        cap >> img;
        cap >> img;
        img.copyTo(image1);
        img.copyTo(image2);

        //dm.QrCode(image1, str);
        //dm.trafficLights(image2);

        if(str.size() == 0) {
            dm.QrCode(image1, str);
            if(str.size() != 0)
                dm.serialSend1(str);
            cout << "二维码识别结果：" << str;
        }
        else 
		{
			if (count < 3)
			{
				if (dm.trafficLights(image2))
				{
					int fd;
					if (wiringPiSetup() < 0)
						return 1;
					if ((fd = serialOpen("/dev/MYUSB", 115200)) < 0)
						return 1;
					serialPuts(fd, "5");
					serialClose(fd);
					cout << "识别到绿灯！";
					count++;
				}
			}
			else {
				dm.QrCode(image1, str2);
				if (str2.size != 0)
				{
					int fd;
					if (wiringPiSetup() < 0)
						return 1;
					if ((fd = serialOpen("/dev/MYUSB", 115200)) < 0)
						return 1;
					serialPuts(fd, "6");
					serialClose(fd);
					cout << "二维码识别结果：" << str;
				}
			}
        }
        imshow("imput",img);
        waitKey(10);
    }
    return 0;
}
