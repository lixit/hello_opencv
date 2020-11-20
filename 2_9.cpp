#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv ) {
	cv::Mat img_rgb, img_gry, img_pyr, img_pyr2, img_cny;

	img_rgb = cv::imread( argv[1] );
	cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::pyrDown( img_gry, img_pyr );
	cv::pyrDown( img_pyr, img_pyr2 );
	cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );


	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at< cv::Vec3b >(y, x);
	// ( Note: We could write img_rgb.at< cv::Vec3b >(x,y)[0] )
	//
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	std::cout << "At (x,y) = (" << x << ", " << y << "): (blue, green, red) = (" <<
	(unsigned int)blue << ", " << (unsigned int)green << ", " <<
	(unsigned int)red << ")" << std::endl;

	std::cout << "Gray pixel there is: " <<
	(unsigned int)img_gry.at<uchar>(y, x) << std::endl;

    x /= 4; y /= 4;
    std::cout << "Pyramid2 pixel there is: " <<
    (unsigned int)img_pyr2.at<uchar>(y, x) << std::endl;
    img_cny.at<uchar>(y, x) = 255; // Set the Canny pixel there to 128

//    cv::namedWindow( "Example rgb", cv::WINDOW_AUTOSIZE );
//    cv::namedWindow( "Example pyr", cv::WINDOW_AUTOSIZE );
//    cv::namedWindow( "Example Pyramid2", cv::WINDOW_AUTOSIZE );

    cv::imshow( "Example rgb", img_rgb );
    cv::imshow( "Example gry", img_gry );
    cv::imshow( "Example Pyramid2", img_pyr2 );
    cv::imshow( "Example canny", img_cny );


	cv::waitKey(0);
}
