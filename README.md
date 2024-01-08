# 2D Poisson Heat Equation Solver

## Overview

This C++ program provides a solver for the steady-state 2D heat equation with Dirichlet boundary conditions. It offers two methods for solving the equation: Jacobi and Gauss-Seidel.

This project implements a solver for the 2D Poisson heat equation using C++. It leverages advanced numerical methods and efficient programming practices to provide a robust and high-performance solution for simulating heat distribution in two-dimensional spaces.

## Project Structure

- **src/**: Contains the main source files of the project.
  - **functions/**: Directory for function implementations relevant to the solver.
  - **main.cpp**: The main entry point of the application.
  - **CMakeLists.txt**: CMake configuration file for the source directory.
- **tests/**: Contains unit tests for the solver.
  - **jacobiTest.cpp**: Unit tests for the Jacobi method implementation.
  - **jacobiTest.h**: Header file for the Jacobi method tests.
  - **CMakeLists.txt**: CMake configuration file for the tests directory.
- **build/**: Directory for build files (typically not checked into version control).
- **CMakeLists.txt**: Main CMake configuration file for the entire project.
- **.gitignore**: Git ignore file to exclude specific files and directories from version control.
- **README.md**: (This file) Provides a comprehensive guide to the project.

## Building the Project

To build the project, follow these steps:

1. Ensure CMake is installed on your system.
2. Navigate to the root directory of the project.
3. Run the following commands:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Running the Solver

After building the project, you can run the solver by executing the binary created in the `build/` directory. Follow these steps:

1. Navigate to the `build/` directory.
2. Execute the solver binary. The command may vary depending on the name of the binary, but typically it will be something like:

   ```bash
   ./src/PDEsolver
   ```

## Testing

The project includes unit tests, particularly for the Jacobi iterative method. To run the tests, navigate to the `build/` directory and execute:

    ./src/PDEsolver --test
