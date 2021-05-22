#ifndef LOW_PASS_H
#define LOW_PASS_H


#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

class LowPass{

private:
    cv::Mat _imag;

    void _single_channel_blur(cv::Mat&, int, int);
    void _multiple_channels_blur(cv::Mat&, int, int);

    void _single_channel_gaussian_blur(cv::Mat&, int, int, int, int);
    void _multiple_channels_gaussian_blur(cv::Mat&, int, int, int, int);

    void _single_channel_median(cv::Mat&, int);
    void _multiple_channels_median(cv::Mat&, int);


public:
    LowPass(){};
    LowPass(cv::Mat&);

    void compute_blur(cv::Mat&, int, int);
    void compute_gaussian_blur(cv::Mat&, int, int);
    void compute_gaussian_blur(cv::Mat&, int, int, int, int);
    void compute_median(cv::Mat&, int);

    
};

#endif