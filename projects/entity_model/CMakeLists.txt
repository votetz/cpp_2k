cmake_minimum_required(VERSION 3.10)
project(entity_model)

# Указываем файлы напрямую.
# Если они лежат в папке src, добавьте префикс src/ к именам.
add_executable(${PROJECT_NAME}
        src/entity_model.cpp
        include/entity_model.hpp
)

# Папки для поиска заголовочных файлов
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Настройка пути для EXE
set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/bin/Windows/AMD64")

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIR}"
)