#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "image_reader.h"


using namespace std;

ImagReader::ImagReader(string path){
    cout << "\nhello world from image reader\n" << endl;
    cv::Mat image;
    image = cv::imread("woman_blonde.tif");
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

}