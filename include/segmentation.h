#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>

#include "smoothing.h"


class SegmenTation{

private:
    cv::Mat _imag;
    cv::Mat _im_remov_back;

public:
    SegmenTation(){};
    SegmenTation(cv::Mat&);

    void compute_background_removing(cv::Mat&, std::string);
    void compute_background_removing(std::string, int);
    void get_image_after_background_removing(cv::Mat&);

};


#endif // SEGMENTATION_H