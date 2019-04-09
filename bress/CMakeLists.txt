cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(bress)
aux_source_directory(. bress)
add_executable(a ${bress})