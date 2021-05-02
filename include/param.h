#ifndef PARAM_H
#define PARAM_H

#include <iostream>
#include <string>
//typedef
 struct Inputs {

    std::string image_path;
    std::string image_name;

    std::string video_path;
    std::string video_name;
};


namespace SetInput {

    void Init(Inputs *);

};


#endif