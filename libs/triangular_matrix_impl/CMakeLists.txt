cmake_minimum_required(VERSION 3.16)
project(triangular_matrix_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCES
        src/diagonal_matrix.cpp
        src/lower_triangular_matrix.cpp
        src/upper_triangular_matrix.cpp
        src/symmetric_matrix.cpp
)

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
