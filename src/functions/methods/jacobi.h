#ifndef _JACOBI_H_
#define _JACOBI_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @file Jacobi.h
 * @brief Function for performing the Jacobi iterative method on a mesh.
 */

/**
 * @brief Performs the Jacobi iterative method on a mesh.
 *
 * Applies the Jacobi iterative method to approximate solutions to a discretized
 * domain. The function iterates until the maximum difference between successive
 * iterations is less than the specified tolerance or the maximum number of
 * iterations is reached.
 *
 * @param mesh Reference to the Mesh object to perform iterations on.
 * @param tol Tolerance level for convergence.
 * @param maxIterations Maximum number of iterations to perform.
 */
void jacobi(Mesh &mesh, const double tol, const size_t maxIterations);

#endif