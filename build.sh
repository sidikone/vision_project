#!/bin/bash

clear
cd build
#rm -r *
cmake ..
make

cp visApps ../.
cp libvision.a ../.
cd ..
./visApps
