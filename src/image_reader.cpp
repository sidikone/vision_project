#include "image_reader.h"

using namespace cv;
using namespace std;


ImagReader::ImagReader(string path){

    _image = imread(path);
}


void ImagReader::getImage(cv::Mat& ref_out){
    ref_out = _image;
}


Mat* ImagReader::getImage(){
    return &_image;
}


ImagReader::~ImagReader(){
 //   destroyWindow(_window_name);
}