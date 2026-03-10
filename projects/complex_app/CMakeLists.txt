project(complex_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC}
        ../func_series/src/func_series.cpp
        ../func_series/include/func_series.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} complex)