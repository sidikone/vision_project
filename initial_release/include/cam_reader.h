#ifndef CAM_READER_H
#define CAM_READER_H

#include <opencv2/highgui.hpp>
#include "video_reader.h"

#include <iostream>
#include <string>

class CamReader : public VideoReader {

private:

public:
    CamReader(int);

};


#endif