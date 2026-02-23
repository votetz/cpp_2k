cmake_minimum_required(VERSION 3.15)
project(sizing)

add_executable(${PROJECT_NAME} src/sz.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)