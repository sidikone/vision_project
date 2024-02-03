#include "video_reader.h"

using namespace cv;
using namespace std;

VideoReader::VideoReader(string path){
    _video.open(path);

    if (!_video.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
    }
}

void VideoReader::showVideo(string window_name, int delta, string typ, bool disp){

    // Mat imag;
    // Mat* imag_ptr;
    // ImagReader imag_1;
    if (disp){
        namedWindow(window_name, WINDOW_AUTOSIZE);
    }
    // int i = 0;
    for (;;){
        _video >> raw_imag;
        if (raw_imag.empty()) {
            break;
        }
        if (typ == "gray"){
            ImagReader imag_1(raw_imag);
            imag_1.openImage(raw_imag);
            imag_ptr = imag_1.color2gray();
            if (disp){
                imshow(window_name, *imag_ptr);
            }
        }

        else if (typ == "hsv") {
            ImagReader imag_1(raw_imag);
            // imag_1.openImage(imag);            
            imag_ptr = imag_1.color2hsv();
            if (disp){
                imshow(window_name, *imag_ptr);
            }
        }

        else {
            imag_ptr = &raw_imag;
            if (disp){
                imshow(window_name, *imag_ptr);
            }
        } 
        if (waitKey(delta) >=0) break;
    }
    if (disp){
        destroyWindow(window_name);
    }
}

VideoReader::~VideoReader(){
//    destroyWindow(_window_name);
}