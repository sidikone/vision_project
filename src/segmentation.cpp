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


void SegmenTation::compute_image_binerization(std::string typ, double value, double max_val){
    
    ImagBinary bin_1(_im_remov_back);
    bin_1.binary_threshold(_im_bin, typ, value, max_val);
}


void SegmenTation::compute_image_cropping(int x_abs, int y_abs){
    int width = _imag.cols - 2*x_abs;
    int height = _imag.rows - 2*y_abs;

    cout << _imag.cols <<"\t"<<_imag.rows << endl;
    cout << width << "\t"<< height <<endl;

    Rect rect_1 (x_abs, y_abs, width, height);
    _im_bin = _im_bin(rect_1);
}


void SegmenTation::connected_components_image_segmenation(){
    nb_obj = connectedComponents(_im_bin, _labels);
    cout << nb_obj << endl;
}


void SegmenTation::get_image_after_background_removing(Mat& imag_out){
    
    imag_out = _im_remov_back;
}


void SegmenTation::get_binary_image(Mat& imag_out){
    
    imag_out = _im_bin;
}