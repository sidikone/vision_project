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

    void compute_canny_edge_detector(cv::Mat&, int, double, double);
    void compute_sobel_edge_detector(cv::Mat&, int, int, int);
    void compute_laplacian_edge_detector(cv::Mat&, int, int, int);

};


#endif // EDGING