cmake_minimum_required(VERSION 3.15)
project(id_parser C)

set(CMAKE_C_STANDARD 99)

add_executable(id_parser main.c parser.h parser.c)

target_link_libraries(id_parser m)