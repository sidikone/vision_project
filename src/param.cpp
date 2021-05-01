#include "param.h"

using namespace std;
using namespace SetInput;

/*void SetInput::say_hello(){
    cout << "hello world from SetInput" << endl;

}*/


/*Inputs SetInput::Init(){
/*    const char image [] = "/home/aboubakar/Images/standard_test_images/cameraman.tif";
    const char *path_imag;
    path_imag = image;

    const char img_name [] = "Cameraman";
    const char *image_name = img_name;

    const char video [] = "/home/aboubakar/Vidéos/Meet_WalkTogether1.mpg";
    const char * path_video = video;

    const char vid_name [] = "Walk together";
    const char *video_name = vid_name;

    cout <<"1. " << image << endl;
    cout <<"2. " << path_imag << endl;
    cout <<"3. " << *path_imag << endl;


    Inputs *input_ptr; 
    Inputs local_input;

    local_input.path_imag = path_imag;
    local_input.image_name = image_name;
    local_input.path_video = video;
    local_input.video_name = vid_name;*/
    
/*    Inputs *input_ptr; 
    Inputs local_input;
    local_input.name = 25;

    cout << local_input.name << endl;

    input_ptr = &local_input;
//    path_in = local_path;
    cout << input_ptr->name << endl;

//    return input_ptr;
    return local_input;
}*/

//static Inputs mama;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    ptr->path_imag = "/home/aboubakar/Images/standard_test_images/cameraman.tif";
    ptr->image_name = "Cameraman";
    ptr->path_video = "/home/aboubakar/Vidéos/Meet_WalkTogether1.mpg";
    ptr->video_name = "Walk together";

}