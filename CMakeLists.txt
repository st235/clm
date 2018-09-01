cmake_minimum_required(VERSION 3.12.0)
set(CMAKE_CXX_STANDARD 14)

project(clm)

set(MAIN src/main.cpp)
set(ARGS src/args/args_parser.h 
         src/args/args_parser.cc
         src/args/args_value.h
         src/args/args_value.cc)
set(CORE src/core/game_logic.h
         src/core/game_logic.cc)
set(UTILS src/utils/string_utils.h
          src/utils/string_utils.cc)

add_executable(clm 
               ${MAIN} ${ARGS} ${CORE} ${UTILS})
