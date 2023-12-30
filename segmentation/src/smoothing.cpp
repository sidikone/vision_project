#include "smoothing.h"

using namespace std;
using namespace cv;

SmooThing::SmooThing(Mat& imag_in){
    this->_imag = imag_in;

}

void SmooThing::_single_channel_blur(cv::Mat& imag_out, int x_ker, int y_ker){
    blur(this->_imag, imag_out, Size(x_ker, y_ker));
};

void SmooThing::_multiple_channels_blur(cv::Mat& imag_out, int x_ker, int y_ker){

    vector <Mat> raw_imag_comp;
    vector <Mat> blur_imag_comp;
    split(this->_imag, raw_imag_comp);

    for (int num=0; num <3; num++){
        Mat ima;
        blur(raw_imag_comp[num], ima, Size(x_ker, y_ker));
        blur_imag_comp.push_back(ima);
    }

    merge(blur_imag_comp, imag_out);
};

void SmooThing::_single_channel_gaussian_blur(cv::Mat& imag_out, int x_ker, int y_ker, int x_std, int y_std){
    GaussianBlur(this->_imag, imag_out, Size(x_ker, y_ker), x_std, y_std);
};

void SmooThing::_multiple_channels_gaussian_blur(cv::Mat& imag_out, int x_ker, int y_ker, int x_std, int y_std){

    vector <Mat> raw_imag_comp;
    vector <Mat> gauss_imag_comp;
    split(this->_imag, raw_imag_comp);

    for (int num=0; num <3; num++){
        Mat ima;
        GaussianBlur(raw_imag_comp[num], ima, Size(x_ker, y_ker), x_std, y_std);
        gauss_imag_comp.push_back(ima);
    }

    merge(gauss_imag_comp, imag_out);
};

void SmooThing::_single_channel_median_blur(cv::Mat& imag_out, int s_ker){
    medianBlur(this->_imag, imag_out, s_ker);
};

void SmooThing::_multiple_channels_median_blur(cv::Mat& imag_out, int s_ker){

    vector <Mat> raw_imag_comp;
    vector <Mat> med_imag_comp;
    split(this->_imag, raw_imag_comp);

    for (int num=0; num <3; num++){
        Mat ima;
        medianBlur(raw_imag_comp[num], ima, s_ker);
        med_imag_comp.push_back(ima);
    }

    merge(med_imag_comp, imag_out); 

};

void SmooThing::_single_channel_bilateral_blur(Mat& imag_out, int s_ker, double color_sig, double space_col){
    bilateralFilter(this->_imag, imag_out, s_ker, color_sig, space_col);
};

void SmooThing::_multiple_channels_bilateral_blur(Mat& imag_out, int s_ker, double color_sig, double space_col){

    vector <Mat> raw_imag_comp;
    vector <Mat> bil_imag_comp;
    split(this->_imag, raw_imag_comp);

    for (int num=0; num <3; num++){
        Mat ima;
        bilateralFilter(raw_imag_comp[num], ima, s_ker, color_sig, space_col);
        bil_imag_comp.push_back(ima);
    }

    merge(bil_imag_comp, imag_out); 

};


// =============================================================================
// -----------------------------------------------------------------------------
void SmooThing::compute_blur(Mat& imag_out, int x_ker, int y_ker){

    int nb_channels = _imag.channels();
    if (nb_channels == 1) _single_channel_blur(imag_out, x_ker, y_ker);
    else _multiple_channels_blur(imag_out, x_ker, y_ker);
}

void SmooThing::compute_gaussian_blur(Mat& imag_out, int x_ker, int y_ker, int x_std, int y_std){

    int nb_channels = _imag.channels();
    if (nb_channels == 1) _single_channel_gaussian_blur(imag_out, x_ker, y_ker, x_std, y_std);
    else _multiple_channels_gaussian_blur(imag_out, x_ker, y_ker, x_std, y_std);
}

void SmooThing::compute_gaussian_blur(Mat& imag_out, int x_ker, int y_ker){

    int nb_channels = _imag.channels();
    if (nb_channels == 1) _single_channel_gaussian_blur(imag_out, x_ker, y_ker, 0, 0);
    else _multiple_channels_gaussian_blur(imag_out, x_ker, y_ker, 0, 0);
}

void SmooThing::compute_median_blur(Mat& imag_out, int s_ker){

    int nb_channels = _imag.channels();
    if (nb_channels == 1) _single_channel_median_blur(imag_out, s_ker);
    else _multiple_channels_median_blur(imag_out, s_ker);

}

void SmooThing::compute_bilateral_filter_blur(Mat& imag_out, int s_ker, double color_sig, double space_col){

    int nb_channels = _imag.channels();
    if (nb_channels == 1) _single_channel_bilateral_blur(imag_out, s_ker, color_sig, space_col);
    else _multiple_channels_bilateral_blur(imag_out, s_ker, color_sig, space_col);

}