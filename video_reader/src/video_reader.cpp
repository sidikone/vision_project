#include "video_reader.h"

using namespace cv;
using namespace std;

VideoReader::VideoReader(string path){
    _video.open(path);

    if (!_video.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
    }

}


void VideoReader::showVideo(string window_name, int delta, string typ){

    Mat imag;
    Mat* imag_ptr;

    for (;;){
        _video >> imag;
        if (imag.empty()) {
            break;
        }
        if (typ == "gray"){
            ImagReader imag_1(imag);
            imag_ptr = imag_1.color2gray();
            imshow(window_name, *imag_ptr);
        }

        else if (typ == "hsv") {
            ImagReader imag_1(imag);
            imag_ptr = imag_1.color2hsv();
            imshow(window_name, *imag_ptr);
        }

        else imshow(window_name, imag);
        if (waitKey(delta) >=0) break;
    }
}


VideoReader::~VideoReader(){
//    destroyWindow(_window_name);
}