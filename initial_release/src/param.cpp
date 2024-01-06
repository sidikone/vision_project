#include "param.h"

using namespace std;
using namespace SetInput;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    ptr->image_path = "../../../dataset_wd/media_files/images/lena_color_512.tif";
    ptr->image_name = "test";
    ptr->video_path = "../../../dataset_wd/media_files/videos/Meet_WalkTogether1.mpg";
    ptr->video_name = "Walk together";

}