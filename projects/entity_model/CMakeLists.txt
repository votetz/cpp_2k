cmake_minimum_required(VERSION 3.10)
project(entity_model)

add_executable(${PROJECT_NAME}
        src/entity_model.cpp
        include/entity_model.hpp
        ../bits/src/main.cpp
        ../bits/include/main.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/bin/Windows/AMD64")

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}"
)