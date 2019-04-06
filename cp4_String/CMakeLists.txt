cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(cp4_String)
aux_source_directory(. cp4_String)
add_executable(a ${cp4_String})