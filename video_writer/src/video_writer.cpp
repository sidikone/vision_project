#include "video_writer.h"
using namespace cv;
using namespace std;


Recording::Recording(string path){
    // this->file_name = file_name;
    _video.open(path);

    if (!_video.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
    }
    else {
        imag_siz = Size((int) _video.get(CAP_PROP_FRAME_WIDTH),    // Acquire input size
                    (int) _video.get(CAP_PROP_FRAME_HEIGHT));        
    }
}

void Recording::SetParameters(string file_name, int m_codec, double m_fps, int m_ratio, bool m_iscolor){
    this->file_name = file_name;
    this->codec = m_codec;
    this->fps = m_fps;
    this->ratio = m_ratio;
    this->iscolor = m_iscolor;
}

void Recording::WriteVideo(string window_name, int delta, string typ, bool disp){

    imag_siz /= 2;

    if (disp){
        namedWindow(window_name, WINDOW_NORMAL);
        resizeWindow(window_name, imag_siz);
    }

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

// VideoWriter::~VideoWriter(){
// //    destroyWindow(_window_name);
// }