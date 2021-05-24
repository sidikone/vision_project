#include "tutorial.h"

using namespace cv;
using namespace std;
using namespace TutoLib;

void TutoLib::image_reader_tutorial(){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a pointer
    string *img_name_ptr = &data_set.image_name;
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;

    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);
    Mat imag;
    Mat *imag_ptr;

    // Get image using pointer or reference
    imag_ptr = image_1.getImage();  
    image_1.getImage(imag);


    // Show image using class or reference or pointer  
    imshow(*img_name_ptr, *imag_ptr);       // 1. pointer 
    cv::waitKey(1000);

    image_1.showImage(*img_name_ptr, "gray"); // 2. class function
    cv::waitKey(1000);

    imshow(*img_name_ptr, imag);       // 1. reference 
    cv::waitKey(1000);
    
    destroyWindow(*img_name_ptr);

    // Second Constructor, the class is constructed using cv::Mat obj
    ImagReader image_2(imag);
}


void TutoLib::video_reader_tutorial(){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);

    string *img_name_ptr = &data_set.image_name;   // Get the file name into a pointer
    string &img_name_ref = data_set.image_name;    // Get the file name into a reference
    
    // Read Video from path
    VideoReader video_1(data_set.video_path);   

    string *video_name_ptr = &data_set.video_name;
    video_1.showVideo(*video_name_ptr, 20, "hsv");
    destroyWindow(*video_name_ptr);

}


void TutoLib::camera_reader_tutorial(){

    namedWindow("Camera", WINDOW_AUTOSIZE);
    CamReader cam_1(0);
    cam_1.showVideo("Camera", 33, "hsv");
    destroyWindow("Camera");
}


void TutoLib::image_writer_tutorial(bool disp){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;
    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);

    Mat imag;
    image_1.color2gray(imag);

    if (disp){
        imshow(img_name_ref, imag);
        waitKey(1000);
        destroyWindow(img_name_ref);
    }

    ImagWriter save_1(imag);
    save_1.saveImage("./../out/images/imag_out.tif");

    ImagWriter save_2(image_1, "hsv");
//    save_2.open(image_1);
    save_2.saveImage("./../out/images/imag_out_2.png");
}


void TutoLib::smoothing_tutorial(bool disp){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;
    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);

    Mat imag;
    Mat imag_out;
//    image_1.color2gray(imag);
    image_1.getImage(imag);

    SmooThing smoot_1(imag);
//    smoot_1.compute_gaussian_blur(imag_out, 11, 11, 0, 0);
//    smoot_1.compute_gaussian_blur(imag_out, 11, 11);
//    smoot_1.compute_blur(imag_out, 11, 11);
//    smoot_1.compute_median_blur(imag_out, 11);
    smoot_1.compute_bilateral_filter_blur(imag_out, 5, 200.0, 200.0);

    if (disp){
        imshow(img_name_ref, imag);
        imshow(img_name_ref+" gaussian", imag_out);
        waitKey(1000);
        waitKey(0);
        destroyWindow(img_name_ref);
    }



 /*   save_1.saveImage("./../out/images/imag_out.tif");

    ImagWriter save_2(image_1, "hsv");
    save_2.saveImage("./../out/images/imag_out_2.png");*/
}


void TutoLib::image_binary_tutorial(bool disp){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;
    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);

    Mat imag;
    Mat imag_out;
    Mat imag_out_2;
    image_1.color2gray(imag);

    ImagBinary binary_1(imag);
    binary_1.binary_threshold(imag_out, "bin", 100, 225);

    ImagBinary binary_2(imag);
    binary_2.binary_threshold(imag_out_2, "to_zero_inv", 100, 255);


    if (disp){
        imshow(img_name_ref, imag);
        imshow(img_name_ref+" binnary", imag_out);
        imshow(img_name_ref+" specific binnary", imag_out_2);
        waitKey(1000);
        waitKey(0);
        destroyWindow(img_name_ref);
    }



 /*   save_1.saveImage("./../out/images/imag_out.tif");

    ImagWriter save_2(image_1, "hsv");
    save_2.saveImage("./../out/images/imag_out_2.png");*/
}


void TutoLib::histogram_tutorial(){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);

    // Get the file name into a pointer
    string *img_name_ptr = &data_set.image_name;

    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;

    // Read Image from path
    ImagReader image_1(data_set.image_path);
    image_1.imageInfo();
    Mat imag;
    Mat *imag_ptr;

    // Get image using pointer or reference
    imag_ptr = image_1.getImage();  
    image_1.getImage(imag);
//    image_1.color2gray(imag);

    imshow(img_name_ref, imag);       // 1. reference 
    cv::waitKey(2000);

    Mat imag_out;

    HistoGram hist_1(imag);
    hist_1.settings(100);
    hist_1.computeHistogram(false);
    cv::waitKey(100);

    hist_1.histogramEqualization(imag_out, true, "hsv");
    cv::waitKey(2000);
    destroyWindow(img_name_ref);
    
}