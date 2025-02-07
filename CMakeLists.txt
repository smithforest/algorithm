cmake_minimum_required(VERSION 3.30)
project(algorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(algorithm main.c
        sqList/SqList.c
        sqList/SqList.h)
