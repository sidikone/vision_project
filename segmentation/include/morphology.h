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

    void compute_image_erosion(cv::Mat&, std::string, int);
    void compute_image_dilation(cv::Mat&, std::string, int);

    void compute_image_opening(cv::Mat&, std::string, int);
    void compute_image_closing(cv::Mat&, std::string, int);

    void compute_image_gradient(cv::Mat&, std::string, int);
    void compute_image_tophat(cv::Mat&, std::string, int);
    void compute_image_blackhat(cv::Mat&, std::string, int);
};

#endif // MORPHOLOGY_H