#include "watershed_segmentation.h"

using namespace std;
using namespace cv;

WatershedSeg::WatershedSeg(Mat& image_in){
    _imag = image_in;
}

void WatershedSeg::compute_markers(Mat& imag_bin, int morph_siz){

    Mat fg;
    Mat bg;
    Mat marker(imag_bin.size(), CV_8U, cv::Scalar(0));
    
    MorPhology morph_1(imag_bin);
    morph_1.compute_image_erosion(fg, "rect", morph_siz);
    morph_1.compute_image_dilation(bg, "rect", morph_siz);

    threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);
    marker = fg+bg;
    _markers = marker;
    _markers.convertTo(_markers,CV_32S);
}

void WatershedSeg::compute_watershed(Mat& marker_out){
    watershed(_imag, _markers);
    marker_out = _markers;
}

void WatershedSeg::get_segmented_image(cv::Mat& imag_out){
    _markers.convertTo(imag_out, CV_8U);
}


void WatershedSeg::get_segmented_elements(cv::Mat& imag_out){
    _markers.convertTo(imag_out, CV_8U, 255, 255);

}