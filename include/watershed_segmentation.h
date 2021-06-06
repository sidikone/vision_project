#ifndef WATERSHED_SEGMENTATION_H
#define WATERSHED_SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include "morphology.h"

class WatershedSeg{

private:

    cv::Mat _imag;
    cv::Mat _markers;

public:

    WatershedSeg(){};
    WatershedSeg(cv::Mat&);

    void compute_markers(cv::Mat&, int);
    void compute_watershed(cv::Mat&);

    void get_segmented_image(cv::Mat&);
    void get_segmented_elements(cv::Mat&);

};

#endif // WATERSHED_SEGMENTATION_H