cmake_minimum_required(VERSION 3.28)
project(mat_as_arr)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCE_FILES src/*)
add_executable(mat_as_arr ${SOURCE_FILES})