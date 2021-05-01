#include <iostream>
#include <opencv2/highgui.hpp>

#include "image_reader.h"
#include "video_reader.h"
#include "cam_reader.h"

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

    Mat imag;
    Mat *imag_ptr = &imag;

    Mat *imag_ptr2;

    namedWindow(image_name, WINDOW_AUTOSIZE);
    ImagReader image_1(path_imag);
//    imag = image_1.getImage();
    
//    image_1.getImage(imag_ptr2);
//    image_1.getImage(imag_ptr);
//    imshow(image_name, *imag_ptr);

    imag_ptr2 = image_1.getImage();
    imshow(image_name, *imag_ptr2);
    cv::waitKey(1000);



//    image_1.showImage("Lena");

/*
    cv::waitKey(500);
    cv::waitKey(0);*/



//    image_1.~ImagReader();


/*    Mat _image;
    _image = imread(_path_name);
    namedWindow(_window_name, WINDOW_AUTOSIZE);
    imshow(_window_name, _image);
    
    waitKey(1000);
    destroyWindow(_window_name);*/


/*    VideoReader video_1(path_video);
    video_1.showVideo("Two people meet");
    video_1.~VideoReader();*/

/*    ImagReader image_1(path_imag);
    image_1.showImage("Lena");
    cv::waitKey(500);
    cv::waitKey(0);
    image_1.~ImagReader();*/


//    CamReader cam_1(path_video);
 //   cam_1.showVideo();

    cout << "hello no world" << endl;
    
    return 0;
}