project(triangular_matrix_impl_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(../../libs/triangular_matrix_impl/include)

add_executable(${PROJECT_NAME} ${SRC}
        ../triangular_matrix_impl_app/src/main.cpp
        include/triangular_matrix_app.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} triangular_matrix_impl)