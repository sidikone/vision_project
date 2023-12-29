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
    string *video_name_ptr = &data_set.video_name;
    // string *img_name_ptr = &data_set.image_name;   // Get the file name into a pointer
    // string &img_name_ref = data_set.image_name;    // Get the file name into a reference
    
    // Read Video from path
    namedWindow(*video_name_ptr, WINDOW_AUTOSIZE);
    cout << data_set.video_path << endl;
    VideoReader video_1(data_set.video_path);   
    video_1.showVideo(*video_name_ptr, 33, "gray");
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

    string imag_raw = "raw_image.tif";
    string imag_hsv = "hsv_image.tif";

    Mat imag;
    image_1.color2gray(imag);

    if (disp){
        imshow(img_name_ref, imag);
        waitKey(1000);
        destroyWindow(img_name_ref);
    }

    ImagWriter save_1(imag);
    save_1.saveImage(data_set.image_output_path + imag_raw);

    ImagWriter save_2(image_1, "hsv");
//    save_2.open(image_1);
    save_2.saveImage(data_set.image_output_path + imag_hsv);
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