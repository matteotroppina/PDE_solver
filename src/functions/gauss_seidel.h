#ifndef _GAUSS_SEIDEL_H_
#define _GAUSS_SEIDEL_H_

#include "Mesh.h"
#include "Node.h"
#include <cmath>
#include <memory>
#include <vector>

void gaussSeidel(Mesh &mesh, const double tol, const size_t maxIterations);

#endif
