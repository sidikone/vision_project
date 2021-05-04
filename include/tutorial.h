#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <iostream>
#include <string>
#include <opencv2/highgui.hpp>

#include "image_reader.h"
#include "video_reader.h"
#include "cam_reader.h"
#include "param.h"

namespace TutoLib{

    void image_reader_tutorial();
    void video_reader_tutorial();
    void camera_reader_tutorial();

};

#endif