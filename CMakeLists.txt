cmake_minimum_required(VERSION 4.3)
project(Raytracer_in_one_weekend)

set(CMAKE_CXX_STANDARD 26)

add_executable(Raytracer_in_one_weekend main.cpp
        vec3.h color.h)
