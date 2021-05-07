#include "histogram.h"
#include <iostream>
using namespace cv;
using namespace std;

HistoGram::HistoGram(Mat &imag_in){
    _image = imag_in;
//    cout << "hello from histogram" << endl;
//    imshow("window_name", _image);

}

void HistoGram::compute_single_histogram(){
    _singl_trig = true;
    calcHist(&_image, 1, 0, Mat(), _single_hist, 1, &numbins, &histRange);
    cout << _single_hist << endl;
}


void HistoGram::compute_multiple_histogram(){
    _multpl_trig = true;
    vector<Mat> bgr;
    split(_image, bgr);

    calcHist(&bgr[0], 1, 0, Mat(), _multiple_hist[0], 1, &numbins, &histRange);
    calcHist(&bgr[1], 1, 0, Mat(), _multiple_hist[1], 1, &numbins, &histRange);
    calcHist(&bgr[2], 1, 0, Mat(), _multiple_hist[2], 1, &numbins, &histRange);
}


void HistoGram::openImag(Mat &image_in){
    
    cout << "hello from histogram" << endl;
}

void HistoGram::settings(int bins, int hist_min, int hist_max){

    numbins = bins;
    *range = hist_min;
    *(range+1) = hist_max;
    histRange = range;
}

void HistoGram::computeHistogram(Mat &image_out, string channel, bool display){

    if (channel == "all"){

    }
    else if (channel == "blue"){

    }
    else if (channel == "green"){

    }
    else if (channel == "red"){

    }
    else{
        cout << "Computing the grayscale histogram" << endl;
        compute_single_histogram();
        image_out = _single_hist;
        
    }

}

/*
cv::Mat* HistoGram::computeHistogram(string=true){
    
    cout << "hello from histogram" << endl;
}*/