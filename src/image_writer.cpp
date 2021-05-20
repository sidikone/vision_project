#include "image_writer.h"

using namespace cv;
using namespace std;

ImagWriter::ImagWriter(Mat& image_in){
    _imag = image_in;
}


void ImagWriter::saveImage(string fileName){
    imwrite(fileName, _imag);
}