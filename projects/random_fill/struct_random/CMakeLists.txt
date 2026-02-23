cmake_minimum_required(VERSION 3.15)
project(ramdom_fill)

add_executable(struct_random src/struct_random.cpp)

set_target_properties(struct_random PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)