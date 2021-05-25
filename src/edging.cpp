#include "edging.h"

using namespace std;
using namespace cv;

EdGing::EdGing(Mat& image_in){
    this->_imag = image_in;
}

void EdGing::compute_canny_edge_detector(Mat& imag_out, int s_ker, double three_min, double three_max){
    Canny(_imag, imag_out, three_min, three_max, s_ker);
}

void EdGing::compute_sobel_edge_detector(Mat& imag_out, int s_ker, int scale, int delta){

    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    Sobel(_imag, grad_x, CV_16S, 1, 0, s_ker, scale, delta, BORDER_DEFAULT);
    Sobel(_imag, grad_y, CV_16S, 0, 1, s_ker, scale, delta, BORDER_DEFAULT);

    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);

    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, imag_out);
}

void EdGing::compute_laplacian_edge_detector(Mat& imag_out, int s_ker, int scale, int delta){
    Mat imag_int;
    Laplacian(_imag, imag_int, CV_16S, s_ker, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(imag_int, imag_out);
}