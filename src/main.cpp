#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>

#include "image_reader.h"
#include "video_reader.h"
#include "cam_reader.h"
#include "param.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    Inputs data_set;
    SetInput::Init(&data_set);
    string *img_name_ptr = &data_set.image_name;

    Mat *imag_ptr;
    ImagReader image_1(data_set.image_path);
    imag_ptr = image_1.getImage();

    Mat imag;
    image_1.getImage(imag);


//    namedWindow(*img_name_ptr, WINDOW_AUTOSIZE);

    image_1.showImage(*img_name_ptr);
//    imshow(*img_name_ptr, imag);
    cv::waitKey(1000);
    destroyWindow(*img_name_ptr);


    VideoReader video_1(data_set.video_path);
    string *video_name_ptr = &data_set.video_name;
    video_1.showVideo(*video_name_ptr, 5);
    destroyWindow(*video_name_ptr);

    namedWindow("Camera", WINDOW_AUTOSIZE);
    CamReader cam_1(0);
    cam_1.showVideo("Camera", 33);

    cv::waitKey(100);


    return 0;
}