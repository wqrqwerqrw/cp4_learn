cmake_minimum_required(VERSION 3.6)
# avoid some cmake warnings
project(acctabc)
aux_source_directory(. acctabc)
add_executable(a ${acctabc})