#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>


class SegmenTation{

private:
    cv::Mat _imag;

public:
    SegmenTation(){};
    SegmenTation(cv::Mat&);

};


#endif // SEGMENTATION_H