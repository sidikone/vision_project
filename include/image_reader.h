#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class ImagReader{
private:

    const char *_window_name;
    cv::Mat _image;
 //   cv::Mat *_image_ptr = &_image;

public:

    ImagReader(const char *);

//    cv::Mat getImage();
    void getImage(cv::Mat *);

    cv::Mat* getImage();
//    void getImage(cv::Mat *);

    ~ImagReader();
};

#endif