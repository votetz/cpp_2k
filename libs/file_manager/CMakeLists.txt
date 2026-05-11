cmake_minimum_required(VERSION 3.10)
project(file_manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main_window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/file_executor.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/main_window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/file_executor.hpp
)

add_library(file_manager STATIC ${SOURCES} ${HEADERS})

target_link_libraries(file_manager
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)

target_include_directories(file_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
