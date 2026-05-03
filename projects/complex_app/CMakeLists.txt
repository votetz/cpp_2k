project(complex_app)

file(GLOB SRC "src/*.cpp" "src/*.cxx")

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE ${COMMON_DEPS} complex)