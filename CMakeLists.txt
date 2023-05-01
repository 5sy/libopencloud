cmake_minimum_required(VERSION 3.23)
project(cloud C)

set(CMAKE_C_STANDARD 99)

add_library(libcloud SHARED
        src/lib.def
        src/lib.c src/lib.h
        src/utils/http.c src/utils/http.h
        src/utils/ini.c src/utils/ini.h
        src/config/config.c src/config/config.h)
target_link_libraries(libcloud Winhttp)
