cmake_minimum_required(VERSION 2.6)

# avoid some cmake warnings
project(ddd)

aux_source_directory(. CMakeTest_1)
add_executable(ddd ${CMakeTest_1})