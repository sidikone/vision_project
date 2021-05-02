#include "video_reader.h"

using namespace cv;
using namespace std;

VideoReader::VideoReader(string path){
    _video.open(path);
}


void VideoReader::showVideo(string window_name, int delta){

    Mat imag;
    for (;;){
        _video >> imag;
        if (imag.empty()) break;
        imshow(window_name, imag);
        if (waitKey(delta) >=0) break;
    }
}


VideoReader::~VideoReader(){
//    destroyWindow(_window_name);
}