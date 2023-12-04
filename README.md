# PDE solver

This C++ program provides a solver for the steady-state 2D heat equation with Dirichlet boundary conditions. It offers two methods for solving the equation: Jacobi and Gauss-Seidel.

## Table of Contents

- [Overview](#overview
- [Building](#building)

## Overview

The 2D heat equation describes the distribution of heat in a 2D domain over time. This program solves for the steady-state temperature distribution within a rectangular domain with fixed temperature values at the boundary.

## Building

To compile the program, make sure you have a C++ compiler installed, such as g++, and navigate to the project directory in your terminal. Then, run the following command:

- mkdir build
- cd build
- cmake ..
- make
