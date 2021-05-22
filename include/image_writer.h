#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <opencv2/imgcodecs.hpp>

#include <iostream>

class ImagReader; // for friendly function

class ImagWriter {

private:
    cv::Mat _imag;


public:
    void __set_data_from_ImagReader(ImagReader&, std::string);
    ImagWriter(){};
    ImagWriter(cv::Mat&);
    ImagWriter(ImagReader&, std::string);

    void saveImage(std::string);
    void open(ImagReader&, std::string);

};

#endif