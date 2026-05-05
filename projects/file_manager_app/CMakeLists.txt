cmake_minimum_required(VERSION 3.16)

project(file_manager_app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../libs/file_manager/include)

set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/dist/bin/Windows/AMD64"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        file_manager
        Qt6::Core
        Qt6::Widgets
        Qt6::Gui
)