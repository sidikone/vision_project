#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <vector>

class ImagReader{

private:

    cv::Mat _image;
    cv::Mat _image_hsv;
    cv::Mat _image_gray;
    std::vector <cv::Mat> _imag_channels;

    bool gray_trig = false;
    bool hsv_trig = false;

    void convert_gray();
    void convert_hsv();

//    void split_components(std::string="clr");
    void split_components(std::string="clr");

public:

    // Class Constructor
    ImagReader(){};
    ImagReader(std::string);
    ImagReader(cv::Mat&);

    void openImage(cv::Mat&);
    void showImage(std::string="Image", std::string="raw");

    // Image getter
    void getImage(cv::Mat&);
    cv::Mat* getImage();

    // Color image conversion
    cv::Mat* color2gray();
    void color2gray(cv::Mat&);

    // Color Image conversion hsv
    cv::Mat* color2hsv();
    void color2hsv(cv::Mat&);

    // Image component
    std::vector<cv::Mat>* getImagComponents(std::string="clr");
    void getImagComponents(std::vector<cv::Mat>&, std::string="clr");

    // Image Info
    void imageInfo();

    virtual ~ImagReader();


    // friend class

};

#endif