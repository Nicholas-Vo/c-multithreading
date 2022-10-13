cmake_minimum_required(VERSION 3.21)
project(pthreads C)

set(CMAKE_C_STANDARD 99)

add_executable(pthreads passing_struct.c sum.c)
