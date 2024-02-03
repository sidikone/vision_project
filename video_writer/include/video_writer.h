#ifndef RECORDING_H
#define RECORDING_H

#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include "video_reader.h"
#include <iostream>
#include <string>

class Recording : public VideoReader {

private:

    cv::VideoWriter _writer;
    std::string file_name;
    int codec;
    bool iscolor;
    int ratio;
    double fps;

public:
    Recording(){};
    Recording(std::string);
    void SetParameters(std::string, int, double, int, bool=true);
    void WriteVideo(std::string="Video", int=33, std::string="clr", bool disp=true);

    // ~VideoWriter();

};


#endif