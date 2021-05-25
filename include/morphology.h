#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>

class MorPhology {

private:
    cv::Mat _imag;
public:
    MorPhology(){};
    MorPhology(cv::Mat&);

};

#endif // MORPHOLOGY_H