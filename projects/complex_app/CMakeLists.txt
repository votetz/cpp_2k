project(complex_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC}
        ../template_utils/src/template_example.cpp
        ../template_utils/include/template_example.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} complex)