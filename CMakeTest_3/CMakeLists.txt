cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(timett)
aux_source_directory(. CMakeTest_3)
add_executable(timett ${CMakeTest_3})