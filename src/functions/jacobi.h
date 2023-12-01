#ifndef _JACOBI_H_
#define _JACOBI_H_

#include "Mesh.h"
#include "Node.h"
#include <iostream>
#include <memory>
#include <vector>

void jacobi(Mesh &mesh, const double tol, const size_t maxIterations);

#endif