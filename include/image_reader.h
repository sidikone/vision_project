#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

class ImagReader{
private:

    const char *path_name;

public:

    ImagReader(const char *);
    void showImage(const char * = "Image");
};

#endif