cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(time)
aux_source_directory(. CMakeTest_2)
add_executable(a ${CMakeTest_2})