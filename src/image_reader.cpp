#include "image_reader.h"

using namespace cv;
using namespace std;

ImagReader::ImagReader(string path){
    _image = imread(path);
}


void ImagReader::showImage(string window_name = "Image"){
    imshow(window_name, _image);
}

void ImagReader::getImage(cv::Mat& ref_out){
    ref_out = _image;
}


Mat* ImagReader::getImage(){
    return &_image;
}


ImagReader::~ImagReader(){
 //   destroyWindow(_window_name);
}