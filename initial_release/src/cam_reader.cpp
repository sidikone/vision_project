#include "cam_reader.h"


CamReader::CamReader(int cam) : VideoReader(){
    _video.open(cam);
}