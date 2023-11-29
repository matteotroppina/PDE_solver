cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src)
project(PDEsolver
    DESCRIPTION "PDE solver for the steady-state solutions for the 2D heat equation.")

add_subdirectory(${SRC})