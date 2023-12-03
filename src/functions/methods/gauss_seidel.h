#ifndef _GAUSS_SEIDEL_H_
#define _GAUSS_SEIDEL_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

void gaussSeidel(Mesh &mesh, const double tol, const size_t maxIterations);

#endif
