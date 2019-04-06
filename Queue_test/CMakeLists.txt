cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(Queue_test)
aux_source_directory(. Queue_test)
add_executable(a ${Queue_test})