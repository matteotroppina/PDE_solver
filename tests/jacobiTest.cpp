#include "src/functions/methods/jacobi.h"
#include "src/functions/input/boundaries.h"
#include "src/functions/objects/Mesh.h"
#include "src/functions/objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

bool testJacobi() {
    size_t rows = 50;
    size_t cols = 50;
    double T0 = 100;           // constant temperature at left and right sides
    double tol = 1e-5;         // convergence tolerance
    int maxIterations = 10000; // maximum number of iterations

    // Initialize mesh and set boundary conditions
    Mesh myMesh(rows, cols);
    setBoundary(myMesh, "Left", T0);
    setBoundary(myMesh, "Right", T0);
    setBoundary(myMesh, "Top", 0);
    setBoundary(myMesh, "Bottom", 0);

    // Run Gauss-Seidel solver
    jacobi(myMesh, tol, maxIterations);

    // Check if the temperature at each point in the mesh is close to T0
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (std::fabs(myMesh.getNode(i, j) - T0) > tol) {
                std::cout << "Test Failed: Temperature at (" << i << ", " << j
                          << ") is incorrect." << std::endl;
                return false;
            }
        }
    }

    return true;
};