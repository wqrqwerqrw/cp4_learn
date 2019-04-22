cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(gou)
aux_source_directory(. gouzao)
add_executable(a ${gouzao})