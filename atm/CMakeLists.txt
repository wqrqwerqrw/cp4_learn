cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(atm)
aux_source_directory(. atm)
add_executable(a ${atm})