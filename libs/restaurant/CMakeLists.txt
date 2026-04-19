cmake_minimum_required(VERSION 3.10)
project(restaurant_lib)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/restaurant/*.hpp)

add_library(restaurant_lib STATIC ${SOURCES} ${HEADERS})

target_include_directories(restaurant_lib PUBLIC include)
