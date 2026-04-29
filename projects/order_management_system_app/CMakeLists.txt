project(order_management_system_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(../../libs/bank_account/include)

add_executable(${PROJECT_NAME} ${SRC}
        ../order_management_system_app/src/main.cpp
        ../order_management_system_app/include/management_system.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} order_management_system)