#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    cv::Vec<int, 4> v1;
    cv::Vec4i v2;
    cv::Vec2f v3(1.0, 2.0);

    cv::Matx<float, 2, 2> m1;
    cv::Matx22f m2(1.0, 2.0, 3.0, 4.0);

    cv::Point p1;
    cv::Point2i p2(3, 4);
    cv::Point3f p3;
    cv::Point2f p4;

    //four-dimensional point class
    cv::Scalar s1;
    cv::Scalar s2(1.0, 2.0, 3.0, 4.0);

    cv::Size si1;
    cv::Size2f si2;
    cv::Size2i si3(3, 4);

    cv::Rect r1;
    cv::Rect r3(p1, si3); //Construct from origin and size
    r3.contains(p1);

    cv::RotatedRect r2;
    cv::RotatedRect r4(p4, si2, 0.3); //Point, Size, and angle

    cv::Complexf c1(1.0, 2.0);
    c1.im; c1.re;


}
