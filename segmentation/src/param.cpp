#include "param.h"

using namespace std;
using namespace SetInput;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    ptr->image_path = "../../../../dataset_wd/media_files/images/4.2.07.tiff";
    ptr->image_name = "Impact";
    ptr->image_output_path = "output/";

    ptr->video_path = "../../../../dataset_wd/media_files/videos/Meet_WalkTogether1.mpg";
    ptr->video_name = "Walk together";

}