#include "image_reader.h"

using namespace cv;
using namespace std;

ImagReader::ImagReader(string path){
    _image = imread(path);
}


ImagReader::ImagReader(cv::Mat& ref_in){
    _image = ref_in;
}


void ImagReader::openImage(cv::Mat& ref_in){
    _image = ref_in;
}


void ImagReader::convert_gray(){
    gray_trig = true;
    cvtColor(_image, _image_gray, COLOR_BGR2GRAY);
}


void ImagReader::convert_hsv(){
    hsv_trig = true;
    cvtColor(_image, _image_hsv, COLOR_RGB2HSV);
}


void ImagReader::split_components(string typ){

    if (typ == "hsv"){
        if (! hsv_trig) convert_hsv();
        split(_image_hsv, _imag_channels);}
    else {
        split(_image, _imag_channels);}

}


void ImagReader::showImage(string window_name, string typ){
    if (typ == "hsv"){
        if (! hsv_trig) convert_hsv();
        imshow(window_name, _image_hsv);
    }
    
    else if (typ == "gray"){
        if (! gray_trig) convert_gray();
        imshow(window_name, _image_gray);
    }

    else imshow(window_name, _image);
    
}

void ImagReader::getImage(cv::Mat& ref_out){
    ref_out = _image;
}


Mat* ImagReader::getImage(){
    return &_image;
}


void ImagReader::color2gray(cv::Mat& ref_out){
    if (! gray_trig) convert_gray();
    ref_out = _image_gray;
}


Mat* ImagReader::color2gray(){
    if (! gray_trig) convert_gray();
    return &_image_gray;
}


void ImagReader::color2hsv(cv::Mat& ref_out){
    if (! hsv_trig) convert_hsv();
    ref_out = _image_hsv;
}


Mat* ImagReader::color2hsv(){
   if (! hsv_trig) convert_hsv();
    return &_image_hsv;
}

std::vector<cv::Mat>* ImagReader::getImagComponents(string typ){
    split_components(typ);
    return &_imag_channels;
}

void ImagReader::getImagComponents(vector<Mat>& out_ref, string typ){
    split_components(typ);
    out_ref = _imag_channels;
}


ImagReader::~ImagReader(){
 //   destroyWindow(_window_name);
}