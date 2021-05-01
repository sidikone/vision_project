#include "image_reader.h"

using namespace cv;
using namespace std;


ImagReader::ImagReader(const char *path){

    _image = imread(path);
}


//Mat ImagReader::getImage(){

//    image_out_ptr = &_image;

/*    _window_name = title;
    Mat image;
    image = imread(_path_name);*/
/*    namedWindow(_window_name, WINDOW_AUTOSIZE);
    cout << mym << endl;*/
//    imshow(_window_name, image);

//    return _image;
//} 

void ImagReader::getImage(cv::Mat *ptr_out){
    ptr_out = &_image;
}


Mat* ImagReader::getImage(){

    cv::Mat *ptr_out = &_image;
    return ptr_out;
}



ImagReader::~ImagReader(){
 //   destroyWindow(_window_name);
}