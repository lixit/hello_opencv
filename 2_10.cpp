#include <opencv2/opencv.hpp>
#include <iostream>

int g_scale = 2;

void onTrackbarSlide( int pos, void *) {
    g_scale = pos;
}

int main( int argc, char** argv ) {
	cv::namedWindow( "Example2_10", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "img_pyr", cv::WINDOW_AUTOSIZE );

	cv::VideoCapture cap;
	if (argc==1)
	{
		cap.open(0); // open the first camera
	}
	else
	{
		cap.open(argv[1]);
	}
	if( !cap.isOpened() )
	{ // check if we succeeded
		std::cerr << "Couldn't open capture." << std::endl;
		return -1;
	}

    cv::createTrackbar("Position", "img_pyr", &g_scale, 8,
                                          onTrackbarSlide);

    cv::Mat frame, img_pyr;
	for(;;)
	{
		cap >> frame;
		if( frame.empty() ) break;
        cv::imshow( "Example2_10", frame );
        cv::pyrDown( frame, img_pyr, cv::Size(frame.cols/g_scale, frame.rows/g_scale));
        cv::imshow( "img_pyr", img_pyr );
		if( cv::waitKey(1) >= 0 ) break;
	}
	// Ran out of film
	return 0;
}
