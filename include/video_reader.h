#ifndef VIDEO_READER_H
#define VIDEO_READER_H

#include <opencv2/highgui.hpp>

#include <iostream>

class VideoReader{

private:
    const char *_path_name;
    const char *_window_name;

public:
    VideoReader(const char *);
    void showVideo(const char * ="Video");
    ~VideoReader();

};

#endif