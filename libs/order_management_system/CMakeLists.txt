project(order_management_system)

file(GLOB_RECURSE SRC LIST_DIRECTORIES true *.cpp *.cxx)

add_library(${PROJECT_NAME} ${SRC}
        include/product.hpp
        ../triangular_matrix_impl/include/upper_triangular_matrix.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_LIB_DEPS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)