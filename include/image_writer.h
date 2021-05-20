#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <opencv2/imgcodecs.hpp>

#include <iostream>


class ImagWriter {

private:
    cv::Mat _imag;

public:
    ImagWriter(cv::Mat&);
    void saveImage(std::string);

};

#endif