#include <opencv2/opencv.hpp>
#include <iostream>

int main(int, char**) {
	cv::VideoCapture vcap;
	cv::Mat image;

	const std::string videoStreamAddress = "http://localhost:5555/video";
	   //open the video stream and make sure it's opened
	if(!vcap.open(videoStreamAddress)) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}

	for(;;) {
		vcap.read(image);
		cv::imshow("Output Window", image);

		if(cv::waitKey(1) >= 0) break;
	}

}
