#include "param.h"

using namespace std;
using namespace SetInput;

void SetInput::Init(Inputs *ptr){
    //static Inputs mama;

    YAML::Node selection = YAML::LoadFile("camera_selection.yaml");
    YAML::Node doc_file = YAML::LoadFile("params.yaml");

    string camera_name = selection[0]["camera"].as<string>();
    string camera_stream = selection[1]["stream"].as<string>();
    string camera_path;

    for (int ind=0; ind <doc_file.size(); ind++){
        if (doc_file[ind]["name"].as<string>() == camera_name){
            camera_path = doc_file[ind][camera_stream].as<string>();
        }
    }

    ptr->video_path = camera_path;
    ptr->video_name = camera_name;

}