# 2D Poisson Heat Equation Solver

## Overview

This project implements a solver for the 2D Poisson steady-state heat equation using C++. It provides Dirichlet boundary conditions and two iterative methods for solving the equation: Jacobi and Gauss-Seidel.

https://gitlab.lrz.de/tum-i05/public/advprog-project-ideas/-/blob/master/pde-solver/pde-solver.md?ref_type=heads

## Project Structure

- **src/**: Contains the main source files of the project.
  - **functions/**: Directory for function implementations relevant to the solver.
  - **main.cpp**
- **tests/**: Contains unit tests for the solver.
  - **jacobiTest.cpp**: Unit tests for the Jacobi method implementation.
- **build/**: Directory for build files
- **.gitignore**: Git ignore file to exclude specific files and directories.
- **README.md**.

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

3. The program will ask you to provide the path to a file that contains the parameters to run the solver and the boundary conditions.
   Provide the path to your file or modify and use the default one:

   ```bash
   ../default.csv
   ```

   which follows the required syntax standard for the parameters definition:

   ```bash
   rows,50
   columns,50
   method,1
   tolerance,0.05
   maxIterations,5000
   outputFile,default_matrix.csv
   topBoundary,sinusoidal,5
   bottomBoundary,constant,10
   leftBoundary,constant,2
   rightBoundary,sinusoidal,2
   ```

## Testing

The project includes unit tests, particularly for the Jacobi iterative method. To run the tests, navigate to the `build/` directory and execute:

    ./src/PDEsolver --test
