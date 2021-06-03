#include "segmentation.h"

#include <opencv2/core/hal/interface.h>

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


void SegmenTation::randomColor(Scalar& color_out){

    Scalar color(
        (double)std::rand() / RAND_MAX * 255,
        (double)std::rand() / RAND_MAX * 255,
        (double)std::rand() / RAND_MAX * 255);
    
    color_out = color;
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

    Mat im_crop;
    Rect rect_1 (x_abs, y_abs, width, height);
    Mat _im_crop_ref (_im_bin, rect_1);
    _im_crop_ref.copyTo(im_crop);

    Mat _new_im;
    copyMakeBorder(im_crop, _im_bin, y_abs, y_abs, x_abs, x_abs, BORDER_CONSTANT);
}


void SegmenTation::display_object_segmenation(bool disp){
    
    srand(time(0));
    _segment = Mat::zeros(_imag.rows, _imag.cols, CV_8UC3);
    
    for(auto i=1; i<nb_obj; i++){
        Scalar random_color;
        randomColor(random_color);
        Mat mask = (_labels==i);
        _segment.setTo(random_color, mask);
    }

    seg_trig = true;
    if (disp) {
        imshow("Segmenation result", _segment);
        waitKey(0);
    }
}


void SegmenTation::display_contour_segmenation(bool disp){
    
    srand(time(0));
    _contours_imag = Mat::zeros(_imag.rows, _imag.cols, CV_8UC3);

    for(auto i=0; i<_contours.size(); i++){
        Scalar random_color;
        randomColor(random_color);
        drawContours(_contours_imag, _contours, i, random_color);
    }

    contour_trig = true;
    if (disp) {
        imshow("Contour finders result", _contours_imag);
        waitKey(0);
    }
}


void SegmenTation::display_object_segmenation(){
    display_object_segmenation(true);
}


void SegmenTation::display_contour_segmenation(){
    display_contour_segmenation(true);
}


void SegmenTation::infos(){
    cout << "there is " << nb_obj-1 << " elements in the scene \n" << endl;
}


void SegmenTation::connected_components_image_segmenation(string typ){
    if (typ == "stats") {
        nb_obj = connectedComponentsWithStats(_im_bin, _labels, _stats, _centroids);
        stats_trig = true;
    }
    else nb_obj = connectedComponents(_im_bin, _labels);
}


void SegmenTation::find_contour_image_segmentation(string typ) {

    if (typ == "all-1") findContours(_im_bin, _contours, _hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
    if (typ == "all-2") findContours(_im_bin, _contours, _hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
    if (typ == "all-3") findContours(_im_bin, _contours, _hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    else findContours(_im_bin, _contours, _hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
}

void SegmenTation::get_image_after_background_removing(Mat& imag_out){
    
    imag_out = _im_remov_back;
}


void SegmenTation::get_binary_image(Mat& imag_out){
    
    imag_out = _im_bin;
}

void SegmenTation::get_segment_labels(cv::Mat& imag_out){
    
    imag_out = _labels;
};


void SegmenTation::get_segmented_image(cv::Mat& imag_out){
    if (!seg_trig) display_object_segmenation(false);
    imag_out = _segment;
};

void SegmenTation::get_labels_centroids(Mat& imag_out){
    
    imag_out = _centroids;
}

void SegmenTation::get_labels_stats(cv::Mat& imag_out){
    
    imag_out = _stats;
};


void SegmenTation::get_contours(PointVect& data_out){
    
    data_out = _contours;
};

void SegmenTation::get_contour_image(cv::Mat& imag_out){
    if (!contour_trig) display_contour_segmenation(false);
    imag_out = _contours_imag;
};