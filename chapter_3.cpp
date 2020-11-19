#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>



int main(int argc, char *argv[])
{
	// Point
	cv::Mat original = cv::imread("/home/x/Documents/landscape.jpeg",cv::IMREAD_UNCHANGED);
	cv::Mat splitChannels[3];
	cv::split(original, splitChannels);
	cv::imshow("B", splitChannels[0]);
	cv::imshow("G", splitChannels[1]);
	cv::imshow("R", splitChannels[2]);

	splitChannels[2] = cv::Mat::zeros(splitChannels[2].size(), CV_8UC1);
	cv::Mat output;
	cv::merge(splitChannels, 3, output);
	cv::imshow("merged", output);

	cv::waitKey();

	cv::Point2i p2i;
	cv::Point2f p2f;
	cv::Point3f p3f;
	cv::Point3f p3f_1(p3f);
	cv::Point3d p3d(1.1, 2.2, 3.3);

	cv::Vec3f v3f = (cv::Vec3f)p3f; //cast to fixed vector class

	p3d.x ,p3d.y, p3d.z;  //member access

	float f = p3f.dot(p3f_1); //dot product
	double d = p3d.ddot(p3f); //double precision dot product

	//Scalar
	cv::Scalar s1;
	cv::Scalar s2(s1);
	cv::Scalar s3(1.1);
	cv::Scalar s4(1.1, 2.2, 3.3, 4.4);
	s4.conj();
	s4.isReal();

	//Size
	cv::Size sz1;
	cv::Size2i sz2i;
	cv::Size2f sz2f;
	cv::Size2f sz4( 1.1, 2.2 );
	sz4.width, sz4.height;  //member access

	//Rect
	cv::Rect r1;
	cv::Rect r2(1, 1, 1, 1);
	cv::Rect r3(p2i, sz2i); //constructed from origin and size
	cv::Rect r4(p2i, p2i); //construct from two corners
	r3.x, r3.y, r3.width, r3.height;
	r3.area();
	cv::Point2i upper_left_corner = r3.tl();
	cv::Point2i bottom_right_corner = r3.br();
	r3.contains(p2i); //determine is point p is inside rectangle r

	//overloaded operators

	//RotatedRect - not a template underneath
	//a container that holds a cv::Point2f
	//called center , a cv::Size2f called size , and one additional float called angle
	cv::RotatedRect rr1();
	cv::RotatedRect rr2(p2f, p2f, p2f);
	cv::RotatedRect rr3(p2f, sz2f, 3.3);
	rr3.center, rr3.size, rr3.angle;
	cv::Point2f pts[4];
	rr3.points(pts);  //return a list of the corners

	//Matx
	cv::Matx<int, 1, 1> m11i;
	cv::Matx33f m33f; cv::Matx43d m43d;
	cv::Matx21f m21f(1.1, 2.2);

	m33f = cv::Matx33f::all(1.1);
	m43d = cv::Matx43d::zeros();
	m21f = cv::Matx21f::ones();
	m33f = cv::Matx33f::eye();

	//Vec - derived from Matx. cv::Vec<> is a cv::Matx<> whose number of columns is one
	//cv::Vec { 2 , 3 , 4 , 6 }{ b , s , w , i , f , d }

	cv::Vec2f v2f;
	cv::Vec2f v2f_2;
	cv::Vec3d v3d(1.1, 2.2, 3.3);
	v2f[0], v2f(0);
//	v2f.cross(v2f_2); // cross product

	//cv::Complexf, cv::Complexd

	cv::Complex<double> z3;
	cv::Complexf z1; cv::Complexd z2;
	cv::Complexd(1, 2);
	z1.re, z1.im;
	z1 = z2.conj();

	cv::alignSize(4, 2);
	float atan = cv::fastAtan2(9, 9);
	cvCeil(3.3);
//	CV_Assert(0);
//	CV_Error( 22, "something" );

	void* p_fastMalloc = cv::fastMalloc(16);
	cv::fastFree(p_fastMalloc);
	std::cout << cv::getNumThreads() << std::endl;
	std::cout << cv::getThreadNum() << std::endl;
	std::cout << cv::getTickCount() << std::endl;
	std::cout << cv::getTickFrequency() << std::endl;
//	std::cout << cvFloor(3.3) << std::endl;

	cv::Mat m;
	m.create(3, 10, CV_32FC3);
	m.setTo(cv::Scalar(1.0f, 0.0f, 1.0f));







}
