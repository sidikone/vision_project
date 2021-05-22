#include "image_writer.h"

#include "image_reader.h" // for friendly function

using namespace cv;
using namespace std;


void ImagWriter::__set_data_from_ImagReader(ImagReader& obj_in, string typ_in){

    if (typ_in == "gray") obj_in.color2gray(_imag);
    else if (typ_in == "hsv") obj_in.color2hsv(_imag);
    else this->_imag = obj_in._image;
}


ImagWriter::ImagWriter(Mat& image_in){
    this->_imag = image_in;
}


ImagWriter::ImagWriter(ImagReader& obj_in, string typ_in){
    __set_data_from_ImagReader(obj_in, typ_in);
}


void ImagWriter::saveImage(string fileName){
    imwrite(fileName, _imag);
}


void ImagWriter::open(ImagReader& obj_in, string typ_in){
    __set_data_from_ImagReader(obj_in, typ_in);

}