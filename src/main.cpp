#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "image_reader.h"

using namespace std;

int main(int argc, char *argv[]){

    cout << "\nhello world\n" << endl;

    cv::Mat image;
    image = cv::imread("lena_color_512.tif");
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", image);

    cv::waitKey(0);

    ImagReader read_one("woman_blonde.tif");

    cv::waitKey(0);
    
    return 0;
}