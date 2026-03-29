cmake_minimum_required(VERSION 3.10)
project(entity_model)

include_directories(include)

add_executable(${PROJECT_NAME}
        src/entity_model.cpp
        include/entity_model.hpp
)

set_target_properties(entity_model PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}"
)