project(tabulate)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC}
        src/app.cpp
        ../func_example/src/func_series.cpp
        ../entity_model/src/entity_model.cpp
        ../entity_model/include/entity_model.hpp
        ../zip_guard/src/main.cpp
        ../box_class/include/box_class.hpp
        ../box_class/src/main.cpp
        ../bank_account_app/src/main.cpp
)