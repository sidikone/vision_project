#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "histogram.h"
#include "image_reader.h"
#include "video_reader.h"

#include "image_writer.h"
#include "smoothing.h"
#include "edging.h"
#include "morphology.h"
#include "segmentation.h"
#include "watershed_segmentation.h"

#include "image_binary.h"
#include "cam_reader.h"
#include "param.h"

namespace TutoLib{

// Reader tutorial
    void image_reader_tutorial();
    void video_reader_tutorial();
    void camera_reader_tutorial();

// Writer tutorial
    void image_writer_tutorial(bool);

// Histogram tutorial
    void histogram_tutorial();

// Binary tutorial
    void image_binary_tutorial(bool);

// Smoothing tutorial
    void smoothing_tutorial(bool);

// Edging tutorial
    void edging_tutorial(bool);

// Morphology tutorial
    void morphology_tutorial(bool);

// Segmentation tutorial
    void segmentation_tutorial(bool);

// Segmentation tutorial
    void watershed_segmentation_tutorial(bool);

};

#endif