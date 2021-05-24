#ifndef EDGING_H
#define EDGING_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>

class EdGing {

private:
    cv::Mat _imag;

public:
    EdGing(){};
    EdGing(cv::Mat&);

};


#endif // EDGING