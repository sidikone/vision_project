#ifndef VIDEO_READER_H
#define VIDEO_READER_H

#include "image_reader.h"
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class VideoReader{

private:

protected:
    cv::VideoCapture _video;

public:
    VideoReader(){};
    VideoReader(std::string);
    void showVideo(std::string="Video", int=33, std::string="clr");
    ~VideoReader();

};

#endif