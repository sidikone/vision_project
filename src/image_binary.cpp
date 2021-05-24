#include "image_binay.h"

using namespace cv;

ImagBinary::ImagBinary(Mat& imag_in){
    _imag = imag_in;
}

void ImagBinary::binary_threshold(cv::Mat& imag_out, std::string typ, double value, double max_val){

    if (typ == "bin_inv") threshold(_imag, imag_out, value, max_val, THRESH_BINARY_INV);
    else if (typ == "trunc") threshold(_imag, imag_out, value, max_val, THRESH_TRUNC);
    else if (typ == "to_zero") threshold(_imag, imag_out, value, max_val, THRESH_TOZERO);
    else if (typ == "to_zero_inv") threshold(_imag, imag_out, value, max_val, THRESH_TOZERO_INV);

    else if (typ == "bin_otsu") threshold(_imag, imag_out, value, max_val, THRESH_OTSU);
    else if (typ == "bin_trian") threshold(_imag, imag_out, value, max_val, THRESH_TRIANGLE);

    else threshold(_imag, imag_out, value, max_val, THRESH_BINARY);

}


void ImagBinary::gaussian_adaptive_binary_threshold(cv::Mat& imag_out, std::string typ, double max_val, int s_ker, double bias){

    if (typ == "bin_inv") adaptiveThreshold(_imag, imag_out, max_val, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, s_ker, bias);
    else adaptiveThreshold(_imag, imag_out, max_val, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, s_ker, bias);

}

void ImagBinary::mean_adaptive_binary_threshold(cv::Mat& imag_out, std::string typ, double max_val, int s_ker, double bias){

    if (typ == "bin_inv") adaptiveThreshold(_imag, imag_out, max_val, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, s_ker, bias);
    else adaptiveThreshold(_imag, imag_out, max_val, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, s_ker, bias);

}