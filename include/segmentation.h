#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <cstdlib>

#include "smoothing.h"
#include "image_binay.h"


class SegmenTation{

private:

    bool seg_trig = false;
    cv::Mat _imag;
    cv::Mat _im_remov_back;
    cv::Mat _im_bin;

    cv::Mat _labels;
    cv::Mat _segment;
    int nb_obj;

    void randomColor(cv::Scalar&);

public:
    SegmenTation(){};
    SegmenTation(cv::Mat&);

// Preprocessing function
    void compute_background_removing(cv::Mat&, std::string);
    void compute_background_removing(std::string, int);
    void compute_image_binerization(std::string typ, double, double);
    void compute_image_cropping(int, int);

    void display_object_segmenation(bool);
    void display_object_segmenation() {display_object_segmenation(true);};

    void infos();

// Processing function

    void connected_components_image_segmenation();
    void get_image_after_background_removing(cv::Mat&);
    void get_binary_image(cv::Mat&);
    void get_segment_labels(cv::Mat&);
    void get_segmented_image(cv::Mat&);

};


#endif // SEGMENTATION_H