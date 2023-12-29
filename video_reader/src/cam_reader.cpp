#include "cam_reader.h"

using namespace std; 

CamReader::CamReader(int cam) : VideoReader(){
    _video.open(cam);
    cout << _video.isOpened() << endl;
}