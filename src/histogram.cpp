#include "histogram.h"
#include <iostream>

using namespace cv;
using namespace std;
using namespace matplot;

HistoGram::HistoGram(Mat &imag_in){
    _image = imag_in;
}


void HistoGram::compute_x_histogram(){

    float step = (*(range+1) - *(range) -1)/numbins;
    for (float idx = *(range); idx < *(range+1)-1; idx+= step){
        _x_hist.push_back(idx);
    }
}


void HistoGram::compute_single_histogram(){

    _singl_trig = true;
    compute_x_histogram();
    calcHist(&_image, 1, 0, Mat(), _single_hist, 1, &numbins, &histRange);
    for (int count = 0; count < numbins; count++){
        _y_hist.push_back(_single_hist.at<float>(count));
    }

    _xy_hist_ptr.x_vector = &_x_hist;
    _xy_hist_ptr.y_vector = &_y_hist;
}


void HistoGram::compute_multiple_histogram(){
    _multpl_trig = true;
    compute_x_histogram();

    vector <Mat> bgr;
    split(_image, bgr);

    for (int num=0; num <3; num++){
        Mat ima;
        calcHist(&(bgr[num]), 1, 0, Mat(), ima, 1, &numbins, &histRange);
        _multiple_hist.push_back(ima);
    }

    vector<float> b_hist;
    vector<float> g_hist;
    vector <float> r_hist;

    for (int count = 0; count < numbins; count++){
        b_hist.push_back(_multiple_hist[0].at<float>(count));
        g_hist.push_back(_multiple_hist[1].at<float>(count));
        r_hist.push_back(_multiple_hist[2].at<float>(count));
    }

    _y_bgr_hist.push_back(b_hist);
    _y_bgr_hist.push_back(g_hist);
    _y_bgr_hist.push_back(r_hist);


    _xy_bgr_hist_ptr.blue.x_vector = &_x_hist;
    _xy_bgr_hist_ptr.blue.y_vector = &_y_bgr_hist[0];

    _xy_bgr_hist_ptr.green.x_vector = &_x_hist;
    _xy_bgr_hist_ptr.green.y_vector = &_y_bgr_hist[1];

    _xy_bgr_hist_ptr.red.x_vector = &_x_hist;
    _xy_bgr_hist_ptr.red.y_vector = &_y_bgr_hist[2];
}


void HistoGram::display_single_histogram(){
    
    bar(_x_hist, _y_hist);
    title("Image histogram");
    xlabel("Niveau de gris");
    ylabel("Occurence");
    show();
}


void HistoGram::display_multiple_histogram(){

    subplot(3, 1, 0);
    bar(_x_hist, _y_bgr_hist[0])->face_color("b");;
    title("Blue - Green - Red Histogram");
    ylabel("Occurence");

    subplot(3, 1, 1);
    bar(_x_hist, _y_bgr_hist[1])->face_color("g");;
    ylabel("Occurence");

    subplot(3, 1, 2);
    bar(_x_hist, _y_bgr_hist[2])->face_color("r");;
    xlabel("Niveau de gris");
    ylabel("Occurence");

    show();
    
}


void HistoGram::openImag(Mat &image_in){
}

void HistoGram::settings(int bins, int hist_min, int hist_max){

    numbins = bins;
    *range = hist_min;
    *(range+1) = hist_max;
    histRange = range;
}

void HistoGram::computeHistogram(string channel, bool display){

    if (_image.channels()== 3){
        compute_multiple_histogram();
        if (display) display_multiple_histogram();

    }
    else{
        compute_single_histogram();
        if (display) display_single_histogram();
        
    }

}

void HistoGram::getHistogram(Mat &hist_out){
    hist_out = _single_hist;
}


void HistoGram::getHistogram(vector<Mat> &hist_out){
    hist_out = _multiple_hist;
}


void HistoGram::getHistogram(std::vector <float> &x_hist_out, std::vector <float> &y_hist_out){
    x_hist_out = _x_hist;
    y_hist_out = _y_hist;
}


void HistoGram::getHistogram(std::vector <float> &x_hist_out, std::vector <std::vector <float>> &bgr_hist_out){
    x_hist_out = _x_hist;
    bgr_hist_out = _y_bgr_hist;
}


void HistoGram::getHistogram(xy_vector_ptr &hist_out){
    hist_out = _xy_hist_ptr;
}


void HistoGram::getHistogram(xy_bgr_vector_ptr &hist_out){
    hist_out = _xy_bgr_hist_ptr;
}
