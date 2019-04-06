cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(time)
aux_source_directory(. CMake_test4)
add_executable(a ${CMake_test4})