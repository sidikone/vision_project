#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "image_reader.h"

using namespace std;

int main(int argc, char *argv[]){

    const char chaine [] = "lena_color_512.tif";
    const char * path = chaine;

    ImagReader image_1(path);
    image_1.showImage("Lena");
    cv::waitKey(0);
    
    return 0;
}