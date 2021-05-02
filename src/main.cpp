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

    namedWindow(*img_name_ptr, WINDOW_AUTOSIZE);
    imshow(*img_name_ptr, imag);
    cv::waitKey(1000);

    return 0;
}