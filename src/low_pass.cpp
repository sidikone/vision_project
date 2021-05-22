#include "low_pass.h"

using namespace std;
using namespace cv;

LowPass::LowPass(Mat& imag_in){
    this->_imag = imag_in;

}

void LowPass::_single_channel_blur(cv::Mat& imag_out, int x_ker, int y_ker){
    blur(this->_imag, imag_out, Size(x_ker, y_ker));
};

void LowPass::_multiple_channels_blur(cv::Mat& imag_out, int x_ker, int y_ker){
//    GaussianBlur(this->_imag, imag_out, Size(x_ker, y_ker));
};

void LowPass::_single_channel_gaussian_blur(cv::Mat& imag_out, int x_ker, int y_ker, int x_std, int y_std){
    GaussianBlur(this->_imag, imag_out, Size(x_ker, y_ker), x_std, y_std);
};

void LowPass::_multiple_channels_gaussian_blur(cv::Mat&, int x_ker, int y_ker, int x_std, int y_std){

};


void LowPass::_single_channel_median(cv::Mat& imag_out, int s_ker){
    medianBlur(this->_imag, imag_out, s_ker);
};

void LowPass::_multiple_channels_median(cv::Mat&, int s_ker){

};



void LowPass::compute_blur(Mat& imag_out, int x_ker, int y_ker){

    int nb_channels = _imag.channels();

    if (nb_channels == 1) {
        _single_channel_blur(imag_out, x_ker, y_ker);
    }

}


void LowPass::compute_gaussian_blur(Mat& imag_out, int x_ker, int y_ker, int x_std, int y_std){

    int nb_channels = _imag.channels();

    if (nb_channels == 1) {
        _single_channel_gaussian_blur(imag_out, x_ker, y_ker, x_std, y_std);
    }

}


void LowPass::compute_gaussian_blur(Mat& imag_out, int x_ker, int y_ker){

    int nb_channels = _imag.channels();

    if (nb_channels == 1) {
        _single_channel_gaussian_blur(imag_out, x_ker, y_ker, 0, 0);
    }

}

void LowPass::compute_median(Mat& imag_out, int s_ker){

    int nb_channels = _imag.channels();

    if (nb_channels == 1) {
        _single_channel_median(imag_out, s_ker);
    }

}