cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

project(c-utils 
    VERSION 1.0 
    DESCRIPTION "Collection of data structures and general utilities"
    LANGUAGES C)

add_library(c_utils_lib STATIC 
    src/algorithms.c 
    src/data_types.c
    src/file_io.c
    src/string_utils.c
)
target_include_directories(c_utils_lib PUBLIC include)
target_compile_features(c_utils_lib PUBLIC c_std_11)

add_executable(c-utils src/main.c)
target_link_libraries(c-utils PUBLIC c_utils_lib)

