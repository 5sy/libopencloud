cmake_minimum_required(VERSION 3.23)
project(cloud C)

set(CMAKE_C_STANDARD 99)

add_library(cloud SHARED
        src/lib.c src/lib.h
        src/lib.def)

