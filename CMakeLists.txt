cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(c-utils 
    VERSION 1.0 
    DESCRIPTION "Collection of data structures and general utilities"
    LANGUAGES C)

add_library(c_utils_lib STATIC 
    src/algorithms.c 
    src/data_types.c
    src/file_io.c
    src/string_utils.c
    include/algorithms.h
    include/data_types.h
    include/file_io.h
    include/string_utils.h
    include/vector.h
)
target_include_directories(c_utils_lib PUBLIC include)
target_compile_features(c_utils_lib PUBLIC c_std_11)

add_executable(c-utils src/main.c)
target_link_libraries(c-utils PUBLIC c_utils_lib)

