#ifndef SMOOTHING_H
#define SMOOTHING_H


#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

class SmooThing{

private:
    cv::Mat _imag;

    void _single_channel_blur(cv::Mat&, int, int);
    void _multiple_channels_blur(cv::Mat&, int, int);

    void _single_channel_gaussian_blur(cv::Mat&, int, int, int, int);
    void _multiple_channels_gaussian_blur(cv::Mat&, int, int, int, int);

    void _single_channel_median_blur(cv::Mat&, int);
    void _multiple_channels_median_blur(cv::Mat&, int);

    void _single_channel_bilateral_blur(cv::Mat&, int, double, double);
    void _multiple_channels_bilateral_blur(cv::Mat&, int, double, double);


public:
    SmooThing(){};
    SmooThing(cv::Mat&);

    void compute_blur(cv::Mat&, int, int);
    void compute_gaussian_blur(cv::Mat&, int, int);
    void compute_gaussian_blur(cv::Mat&, int, int, int, int);
    void compute_median_blur(cv::Mat&, int);
    void compute_bilateral_filter_blur(cv::Mat&, int, double, double);

    
};

#endif