cmake_minimum_required(VERSION 3.31)
project(lab03)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab03 main.cpp
        zadanie.cpp
        zadanie.h
        problem.cpp
        problem.h
        maszyna.cpp
        maszyna.h)
