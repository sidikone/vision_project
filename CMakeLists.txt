#########################################################
### Author : Aboubakar KONE                           ###
### Creation date : 2021-04-25                        ###
### Last update : 2021-04-27                          ###
#########################################################

# -------------------------------------------------------
# Basic setup

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (PJName Vision)
project(${PJName})

# -------------------------------------------------------
# find libraries

#find_library(OpenCV REQUIRED)
find_package(OpenCV REQUIRED)
# -------------------------------------------------------
# src file

file (GLOB SRCS src/*.cpp)

# -------------------------------------------------------
# Include directories

set (INCLUDE include)
include_directories(
    ${INCLUDE}
    ${OpenCV_INCLUDE_DIRS}
                    )

# --------------------------------------------------------
# Executable

add_executable(${PJName} ${SRCS})

# --------------------------------------------------------
# Library

add_library(lib ${SRCS})

# --------------------------------------------------------
# Target link

target_link_libraries(${PJName} lib
                                ${OpenCV_LIBS})
