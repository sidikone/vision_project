#ifndef VIDEO_READER_H
#define VIDEO_READER_H

#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class VideoReader{

private:
    cv::VideoCapture _video;

public:
    VideoReader(std::string);
 /*   void getVideo(cv::VideoCapture& );
    cv::VideoCapture* getVideo();*/
    void showVideo(std::string="Video", int=33);
    ~VideoReader();

};

#endif