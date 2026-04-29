project(bank_account_app)

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(../../libs/bank_account/include)

add_executable(${PROJECT_NAME} ${SRC}
        ../bank_account_app/src/main.cpp
        ../bank_account_app/include/bank_account_app.hpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} bank_account)