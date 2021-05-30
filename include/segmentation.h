#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>

#include "smoothing.h"
#include "image_binay.h"


class SegmenTation{

private:
    cv::Mat _imag;
    cv::Mat _im_remov_back;
    cv::Mat _im_bin;

    cv::Mat _labels;
    int nb_obj;

public:
    SegmenTation(){};
    SegmenTation(cv::Mat&);

// Preprocessing function
    void compute_background_removing(cv::Mat&, std::string);
    void compute_background_removing(std::string, int);
    void compute_image_binerization(std::string typ, double, double);
    void compute_image_cropping(int, int);

// Processing function

    void connected_components_image_segmenation();
    void get_image_after_background_removing(cv::Mat&);
    void get_binary_image(cv::Mat&);

};


#endif // SEGMENTATION_H