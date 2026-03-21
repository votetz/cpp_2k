project(template_utils)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(template_utils ${SRC})