cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set optimization flags for Release configuration
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")

set(SRC src)
project(PDEsolver
    DESCRIPTION "PDE solver for the steady-state 2D heat equation solution.")

add_subdirectory(${SRC})
add_subdirectory(tests)
