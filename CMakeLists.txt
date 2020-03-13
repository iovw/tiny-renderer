cmake_minimum_required(VERSION 3.16)
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(tinyrenderer
        tgaimage.cpp
        tgaimage.h
        main.cpp
        )
