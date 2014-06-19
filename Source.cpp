#include "PTZController.h"

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	CoInitializeEx(NULL, COINITBASE_MULTITHREADED);

	{
		cv::VideoCapture camera(0);
		if (!camera.isOpened())
		{
			exit(-1);
		}
		PTZController ptz(0);

		while (true)
		{
			if (!camera.grab())
			{
				continue;
			}
			cv::Mat im;
			camera.retrieve(im);
			cv::imshow("BCC950", im);
			char c = cv::waitKey(10);
			if (c == 'w')
			{
				ptz.tilt(1);
			}
			if (c == 's')
			{
				ptz.tilt(-1);
			}
			if (c == 'a')
			{
				ptz.pan(-1);
			}
			if (c == 'd')
			{
				ptz.pan(1);
			}
			if (c == '1')
			{
				ptz.zoom(-10);
			}
			if (c == '2')
			{
				ptz.zoom(10);
			}
			if (c == 'q')
			{
				break;
			}
		}
	}

	CoUninitialize();
	return 0;
}