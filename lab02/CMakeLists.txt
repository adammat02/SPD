cmake_minimum_required(VERSION 3.31)
project(lab02)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab02 main.cpp
        maszyna.cpp
        maszyna.h
        zadanie.cpp
        zadanie.h
        problem.cpp
        problem.h)
