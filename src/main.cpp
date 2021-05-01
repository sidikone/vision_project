#include <iostream>
#include <opencv2/highgui.hpp>

#include "image_reader.h"
#include "video_reader.h"
#include "cam_reader.h"
#include "param.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){

    const char image [] = "/home/aboubakar/Images/standard_test_images/cameraman.tif";
    const char *path_imag = image;

    const char img_name [] = "Cameraman";
    const char *image_name = img_name;

    const char video [] = "/home/aboubakar/Vidéos/Meet_WalkTogether1.mpg";
    const char * path_video = video;

    const char vid_name [] = "Walk together";
    const char *video_name = vid_name;

    Mat *imag_ptr;

    namedWindow(image_name, WINDOW_AUTOSIZE);
    ImagReader image_1(path_imag);

    imag_ptr = image_1.getImage();
    imshow(image_name, *imag_ptr);
    cv::waitKey(1000);

    Inputs mytest;
    SetInput::Init(&mytest);

    cout << mytest.image_name << endl;

/*    int popo;
    Inputs *input_ptr;
    Inputs momo;
    momo = SetInput::Init(&popo);

    int *ptr;
    ptr = momo.name_ptr;

    cout <<"\t" << momo.name << "\t" << momo.maya <<endl;

    cout <<"\t" << momo.name_ptr << "\t" << ptr <<endl;

    cout <<"\t toto = " << popo << endl; */

    return 0;
}