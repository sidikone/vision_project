#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <vector>

class HistoGram{

private:
    cv::Mat _image;
    cv::Mat* _image_ptr;

    cv::Mat _single_hist;
    std::vector <cv::Mat> _multiple_hist;

    bool _singl_trig = false;
    bool _multpl_trig = false;

    int numbins;        // Number of bins
    float range[2];      // Set of range BGR
    const float* histRange;

    void compute_single_histogram();
    void compute_multiple_histogram();


public:
    HistoGram(){};
    HistoGram(cv::Mat&);

    void openImag(cv::Mat&);
    void settings(int=256, int=0, int=256);
    void computeHistogram(cv::Mat&, std::string="grayscale", bool=true);
 //   cv::Mat* computeHistogram(std::string=true);



};

#endif