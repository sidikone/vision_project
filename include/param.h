#ifndef PARAM_H
#define PARAM_H

#include <iostream>
#include <string>
//typedef
 struct Inputs {

    std::string path_imag;
    std::string image_name;
    std::string path_video;
    std::string video_name;
};


namespace SetInput {

    void Init(Inputs *);

};


#endif