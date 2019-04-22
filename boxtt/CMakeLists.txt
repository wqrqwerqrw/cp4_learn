cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(a)
aux_source_directory(. boxtt)
add_executable(a ${boxtt})