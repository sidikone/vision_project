#include "video_reader.h"

using namespace cv;
using namespace std;

VideoReader::VideoReader(const char *path){
    _path_name = path;
}


void VideoReader::showVideo(const char *title){

    _window_name = title;
    VideoCapture video;
    video.open(_path_name);
    Mat imag;

    namedWindow(_window_name, WINDOW_AUTOSIZE);
    for (;;){
        video >> imag;
        if (imag.empty()) break;
        cv::imshow(_window_name, imag);
        if (waitKey(33) >=0) break;
    }
}


VideoReader::~VideoReader(){
    destroyWindow(_window_name);
}