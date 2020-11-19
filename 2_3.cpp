#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char *argv[])
{
    cv::namedWindow("Example 3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));

    cv::Mat frame;
    for(;;) {
        cap >> frame;
        if (frame.empty())
            break;
        cv::imshow("Example 3", frame);
        if(cv::waitKey(33) >= 0)
            break;
    }

    return 0;
}
