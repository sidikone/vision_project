#########################################################
### Author : Aboubakar KONE                           ###
### Creation date : 2021-04-25                        ###
### Last update : 2021-04-27                          ###
#########################################################

# -------------------------------------------------------
# Basic setup

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (PJName vision)
set (APPName visApps)
project(${PJName})

# -------------------------------------------------------
# find libraries

# find_library(OpenCV REQUIRED)
# find_package(yaml-cpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Matplot++ REQUIRED)
# -------------------------------------------------------
# src file

file (GLOB SRCS src/*.cpp)

# -------------------------------------------------------
# Include directories

set (INCLUDE include)
include_directories(
    ${INCLUDE}
    ${OpenCV_INCLUDE_DIRS}
    ${YAML_CPP_INCLUDE_DIRS}
                    
)
# include_directories(${YAML_CPP_INCLUDE_DIRS})
# --------------------------------------------------------
# Executable

add_executable(${APPName} ${SRCS})

# --------------------------------------------------------
# Library

add_library(${PJName} SHARED ${SRCS})

# --------------------------------------------------------
# Target link

target_link_libraries(${APPName} ${PJName}
                                Matplot++::matplot
                                ${OpenCV_LIBS}
                                ${YAML_CPP_LIBRARIES}
                                ${CMAKE_SOURCE_DIR}/libyaml-cpp.a
)
