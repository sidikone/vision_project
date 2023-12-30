#include "morphology.h"

using namespace cv;
using namespace std;

MorPhology::MorPhology(Mat& image_in){
    this->_imag = image_in;
}


void MorPhology::compute_image_erosion(Mat& imag_out, string morph_typ, int s_ker){
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));
    erode(_imag, imag_out, element);                
}


void MorPhology::compute_image_dilation(Mat& imag_out, string morph_typ, int s_ker){
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));
    dilate(_imag, imag_out, element);                
}


void MorPhology::compute_image_opening(Mat& imag_out, string morph_typ, int s_ker){
    
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));

    morphologyEx(_imag, imag_out, MORPH_OPEN,element);                
}


void MorPhology::compute_image_closing(Mat& imag_out, string morph_typ, int s_ker){
    
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));

    morphologyEx(_imag, imag_out, MORPH_CLOSE,element);             
}


void MorPhology::compute_image_gradient(Mat& imag_out, string morph_typ, int s_ker){
    
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));

    morphologyEx(_imag, imag_out, MORPH_GRADIENT,element);                
}


void MorPhology::compute_image_tophat(Mat& imag_out, string morph_typ, int s_ker){
    
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));

    morphologyEx(_imag, imag_out, MORPH_TOPHAT,element);             
}


void MorPhology::compute_image_blackhat(Mat& imag_out, string morph_typ, int s_ker){
    
    int pattern_typ;
    if (morph_typ == "rect") pattern_typ = MORPH_RECT;
    else if (morph_typ == "cross") pattern_typ = MORPH_CROSS;
    else pattern_typ = MORPH_ELLIPSE;
    Mat element = getStructuringElement(pattern_typ,
                       Size(2*s_ker + 1, 2*s_ker+1),
                       Point(s_ker, s_ker));

    morphologyEx(_imag, imag_out, MORPH_BLACKHAT,element);             
}