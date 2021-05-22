#include "param.h"

using namespace std;
using namespace SetInput;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    ptr->image_path = "../data/images/lena_color_512.tif";
    ptr->image_name = "lena";
    ptr->video_path = "/../data/videos/Meet_WalkTogether1.mpg";
    ptr->video_name = "Walk together";

}