cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(change_me 
    VERSION 1.0 
    DESCRIPTION "Change me"
    LANGUAGES C)

add_library(change_lib STATIC 
    src/dynamic_array.c 
    include/dynamic_array.h)
target_include_directories(change_lib PUBLIC include)
target_compile_features(change_lib PUBLIC c_std_11)

add_executable(change_me src/main.c)
target_link_libraries(change_me PUBLIC change_lib)

