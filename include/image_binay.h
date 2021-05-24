#ifndef IMAGE_BINARY_H
#define IMAGE_BINARY_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>

class ImagBinary{

private:
    cv::Mat _imag;

public:
    ImagBinary(){};
    ImagBinary(cv::Mat&);

    void binary_threshold(cv::Mat&, std::string, double, double);

};

#endif // IMAGE_BINARY