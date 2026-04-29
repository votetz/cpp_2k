cmake_minimum_required(VERSION 3.10)
project(matrix_class_implementation)

include_directories(include)

add_executable(${PROJECT_NAME}
        include/matrix.hpp
        src/main.cpp
)

set_target_properties(bits PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}"
)