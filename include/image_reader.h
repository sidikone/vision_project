#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class ImagReader{
private:

    cv::Mat _image;

public:

    ImagReader(std::string);
    void showImage(std::string);
    void getImage(cv::Mat& );
    cv::Mat* getImage();
    ~ImagReader();
};

#endif