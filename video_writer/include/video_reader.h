#ifndef VIDEO_READER_H
#define VIDEO_READER_H

#include "image_reader.h"
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <string>

class VideoReader{

private:

protected:
    cv::Mat raw_imag;
    cv::Size imag_siz;
    cv::Mat* imag_ptr;
    cv::VideoCapture _video;

public:
    VideoReader(){};
    VideoReader(std::string);
    void showVideo(std::string="Video", int=33, std::string="clr", bool disp=true);
    ~VideoReader();

};

#endif