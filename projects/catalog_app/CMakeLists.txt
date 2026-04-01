project(catalog_app)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(catalog_app ${SRC}
        include/product.hpp
        src/main.cpp
        include/product_validator.hpp
        src/product.cpp
        include/product_catalog.hpp
)