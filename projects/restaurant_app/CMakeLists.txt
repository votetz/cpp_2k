cmake_minimum_required(VERSION 3.10)
project(restaurant_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(restaurant_app 
    src/main.cpp
    include/app.hpp
)

target_include_directories(restaurant_app PRIVATE include)
target_link_libraries(restaurant_app PRIVATE restaurant_lib)
