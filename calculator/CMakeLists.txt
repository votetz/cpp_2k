# CMakeList.txt: проект CMake для cpp_2k; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
project("calculator")

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})