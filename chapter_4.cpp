#include "opencv2/opencv.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	//default constructor
	cv::Mat m1;
	//two-dimensional arrays by type
	//create data area for 3 rows and 10 columns of 3-channel 32-bit floats
	cv::Mat m2(3, 10, CV_32FC3);
	//two-dimensional arrays by type with initialization value
	cv::Mat m3(3, 10, CV_32FC2,
			   cv::Scalar(1.0f, 0.0f, 1.0f));
	//two-dimensional arrays by type with preexisting data
	cv::Mat m4(3, 10, CV_32FC2,
			m3.data);
	//two-dimensional array by type
	cv::Mat m5(cv::Size(3,4), CV_32FC3);

	//Create a cv::Mat of size rows * cols, which is full of zeros, with type.
	cv::Mat m6 = cv::Mat::eye(10, 10, CV_32FC1);
	printf("%f\n", m6.at<float>(3, 3));
//	std::cout << m6.at<float>(3, 3);

	cv::Mat m7 = cv::Mat::ones(10, 10, CV_32FC2);
	printf( "Element (3,3) is (%f,%f)\n",
			m7.at<cv::Vec2f>(3,3)[0],
			m7.at<cv::Vec2f>(3,3)[1]
			);

	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
	cv::Mat n_mat( 3, n_mat_sz, CV_32FC1 );
	cv::RNG rng;
	rng.fill( n_mat, cv::RNG::UNIFORM, 0.f, 1.f );
	const cv::Mat* arrays[] = { &n_mat, 0 };
	cv::Mat my_planes[1];
	cv::NAryMatIterator it( arrays, my_planes );







//	m.setTo(cv::Scalar(1.0f, 0.0f, 1.0f));

//	cv::Mat m6(3, 10, CV_32FC3, cv::Scalar(1.0f, 0.0f, 1.0f));


	return 0;
}
