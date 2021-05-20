#include "param.h"

using namespace std;
using namespace SetInput;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    ptr->image_path = "../data/images/mandril_color.tif";
    ptr->image_name = "mandril";
    ptr->video_path = "/../data/videos/Meet_WalkTogether1.mpg";
    ptr->video_name = "Walk together";

}