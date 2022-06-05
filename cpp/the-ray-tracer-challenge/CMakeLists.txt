cmake_minimum_required(VERSION 3.10)

# set the project name
project(raytracer VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

configure_file(RaytracerConfig.h.in RaytracerConfig.h)

add_executable(raytracer ./src/raytracer.cpp)