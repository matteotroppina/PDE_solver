#ifndef _GAUSS_SEIDEL_H_
#define _GAUSS_SEIDEL_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @file GaussSeidel.h
 * @brief Function for performing the Gauss-Seidel iterative method on a mesh.
 */

/**
 * @brief Performs the Gauss-Seidel iterative method on a mesh.
 *
 * Applies the Gauss-Seidel iterative method to approximate solutions to a
 * discretized domain. The function iterates until the maximum difference
 * between successive iterations is less than the specified tolerance or the
 * maximum number of iterations is reached.
 *
 * @param mesh Reference to the Mesh object to perform iterations on.
 * @param tol Tolerance level for convergence.
 * @param maxIterations Maximum number of iterations to perform.
 */
void gaussSeidel(Mesh &mesh, const double tol, const size_t maxIterations);

#endif
