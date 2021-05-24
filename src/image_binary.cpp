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
    else threshold(_imag, imag_out, value, max_val, THRESH_BINARY);


}