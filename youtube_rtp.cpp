#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int argv, char **argc)
{
	Mat frame;
//	VideoCapture vid("rtsp://:8554/127.0.0.1");
	VideoCapture vid(0);

	namedWindow("Webcam", cv::WINDOW_NORMAL);

	int fps = (int)vid.get(cv::CAP_PROP_FPS);

	if(!vid.isOpened())
	{
		return -1;
	}

	while(vid.read(frame))
	{
		imshow("Webcam", frame);

		if(waitKey(1000/fps) >= 0)
			break;
	}
	return 0;

}
