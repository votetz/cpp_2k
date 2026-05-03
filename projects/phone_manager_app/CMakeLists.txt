project(phone_manager_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC}
        ../phone_manager_app/src/main.cpp
        ../phone_manager_app/include/app.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} phone_manager)