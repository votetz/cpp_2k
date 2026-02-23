cmake_minimum_required(VERSION 3.15)
project(ramdom_fill)

add_executable(array_random src/array_random.cpp)

set_target_properties(array_random PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)