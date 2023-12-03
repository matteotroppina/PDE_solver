#ifndef _JACOBI_H_
#define _JACOBI_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

void jacobi(Mesh &mesh, const double tol, const size_t maxIterations);

#endif