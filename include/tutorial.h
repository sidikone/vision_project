#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>

#include "histogram.h"
#include "image_reader.h"
#include "video_reader.h"

#include "image_writer.h"

#include "cam_reader.h"
#include "param.h"

namespace TutoLib{

// Reader tutorial
    void image_reader_tutorial();
    void video_reader_tutorial();
    void camera_reader_tutorial();

// Writer tutorial
    void image_writer_tutorial(bool);

    void histogram_tutorial();

};

#endif