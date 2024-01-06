#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <matplot/matplot.h>

//using xy_vector = std::pair <std::map<std::string, std::vector<std::string>>, std::map<std::string, std::vector<float>>>;

 struct xy_vector_ptr {

    std::vector<float>* x_vector;
    std::vector<float>* y_vector;
};

 struct xy_bgr_vector_ptr {

    xy_vector_ptr blue;
    xy_vector_ptr green;
    xy_vector_ptr red;
};

class HistoGram{

private:
    cv::Mat _image;
    cv::Mat* _image_ptr;

    cv::Mat _single_hist;
    cv::Mat _equalized_hist;

    std::vector <cv::Mat> _multiple_hist;

    std::vector <float> _x_hist;
    std::vector <float> _y_hist;

    std::vector <std::vector <float>> _y_bgr_hist;

    xy_vector_ptr _xy_hist_ptr;
    xy_bgr_vector_ptr _xy_bgr_hist_ptr;

    bool _singl_trig = false;
    bool _multpl_trig = false;

    int numbins;        // Number of bins
    float range[2];      // Set of range BGR
    const float* histRange;

    void compute_x_histogram();
    void compute_single_histogram();
    void compute_multiple_histogram();

    void compute_single_histogram_equalization(cv::Mat&);
    void compute_multiple_histogram_equalization(cv::Mat&, std::string);

    void display_single_histogram();
    void display_multiple_histogram();



public:
    HistoGram(){};
    HistoGram(cv::Mat&);

    void openImag(cv::Mat&);
    void settings(int=256, int=0, int=256);
    void computeHistogram(bool=true);
    void histogramEqualization(cv::Mat&, bool, std::string);
    
    void getHistogram(cv::Mat&);
    void getHistogram(std::vector <cv::Mat>&);

    void getHistogram(std::vector <float>&, std::vector <float>&);
    void getHistogram(std::vector <float>&, std::vector <std::vector <float>>&);

    void getHistogram(xy_vector_ptr&);
    void getHistogram(xy_bgr_vector_ptr&);

 //   void computeHistogram(cv::Mat&, std::string="grayscale", bool=true);
 //   cv::Mat* computeHistogram(std::string=true);



};

#endif