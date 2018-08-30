cmake_minimum_required(VERSION 3.12.0)
set(CMAKE_CXX_STANDARD 14)

project(clm)

set(MAIN src/main.cpp)
set (ARGS src/args/args_parser.h src/args/args_parser.cc)

add_executable(clm 
               ${MAIN} ${ARGS})
