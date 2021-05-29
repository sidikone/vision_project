#include "segmentation.h"

using namespace std;
using namespace cv;

SegmenTation::SegmenTation(Mat& imag_in){
    _imag = imag_in;
}


void SegmenTation::compute_background_removing(Mat& ground, string typ){

    if (typ == "sub") _im_remov_back = ground - _imag;
    else {
        Mat img_32;
        Mat ground_32;

        _imag.convertTo(img_32, CV_32F);
        ground.convertTo(ground_32, CV_32F);
        _im_remov_back = 1 - (img_32/ground_32);
        _im_remov_back.convertTo(_im_remov_back, CV_8U, 255);
    }
}


void SegmenTation::compute_background_removing(string typ, int s_ratio){

    Mat estim_back;
    SmooThing sm_1(_imag);
    sm_1.compute_blur(estim_back, _imag.cols/s_ratio, _imag.cols/s_ratio);
    compute_background_removing(estim_back, typ);
}


void SegmenTation::get_image_after_background_removing(Mat& imag_out){
    
    imag_out = _im_remov_back;
}