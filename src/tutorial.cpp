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
}


void TutoLib::edging_tutorial(bool disp){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;
    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);

    Mat imag;
    Mat imag_trans;
    Mat imag_out;
    image_1.color2gray(imag);
    SmooThing smoot_1(imag);
    smoot_1.compute_gaussian_blur(imag_trans, 5, 5);
    EdGing edge_1(imag_trans);
    
//    edge_1.compute_canny_edge_detector(imag_out, 7, 100, 300);
//    edge_1.compute_laplacian_edge_detector(imag_out, 5, 1, 0);
    edge_1.compute_sobel_edge_detector(imag_out, 5, 1, 0);

    if (disp){
        imshow(img_name_ref, imag);
        imshow(img_name_ref+" edging", imag_out);
        waitKey(1000);
        waitKey(0);
        destroyWindow(img_name_ref);
    }
}


void TutoLib::morphology_tutorial(bool disp){

    // Dataset path
    Inputs data_set;
    SetInput::Init(&data_set);
    // Get the file name into a reference
    string &img_name_ref = data_set.image_name;
    // Read Image from path using string constructor
    ImagReader image_1(data_set.image_path);

    Mat imag;
    Mat imag_med;
    Mat imag_out;
    image_1.color2gray(imag);

    ImagBinary binary_1(imag);
//    binary_1.binary_threshold(imag_out, "bin", 100, 255);
    binary_1.mean_adaptive_binary_threshold(imag_med, "bin_inv", 255, 11, 11);
    MorPhology morph_1(imag_med);

//    morph_1.compute_image_erosion(imag_out, "rect", 1);
//    morph_1.compute_image_dilation(imag_out, "rect", 1);
    morph_1.compute_image_opening(imag_out, "rect", 1);
//    morph_1.compute_image_closing(imag_out, "rect", 1);
//    morph_1.compute_image_gradient(imag_out, "rect", 1);
//    morph_1.compute_image_tophat(imag_out, "rect", 1);
//    morph_1.compute_image_blackhat(imag_out, "rect", 1);

    if (disp){
        imshow(img_name_ref, imag);
        imshow(img_name_ref+" bin", imag_med);
        imshow(img_name_ref+" morph", imag_out);
        waitKey(1000);
        waitKey(0);
        destroyWindow(img_name_ref);
    }
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
    binary_1.binary_threshold(imag_out, "bin", 100, 255);

    ImagBinary binary_2(imag);
//    binary_2.binary_threshold(imag_out_2, "bin_otsu", 225, 255);
//    binary_2.gaussian_adaptive_binary_threshold(imag_out_2, "bin", 255, 21, 5);
    binary_2.mean_adaptive_binary_threshold(imag_out_2, "bin", 150, 21, 5);

    if (disp){
        imshow(img_name_ref, imag);
        imshow(img_name_ref+" binnary", imag_out);
        imshow(img_name_ref+" specific binnary", imag_out_2);
        waitKey(1000);
        waitKey(0);
        destroyWindow(img_name_ref);
    }
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