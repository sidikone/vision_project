#include "image_reader.h"

using namespace std;


ImagReader::ImagReader(const char *path){

    path_name = path;
}


void ImagReader::showImage(const char * title){

    cv::Mat image;
    image = cv::imread(path_name);
    cv::namedWindow(title);
    cv::imshow(title, image);
}