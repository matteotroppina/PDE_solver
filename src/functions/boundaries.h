#ifndef _BOUNDARIES_H_
#define _BOUNDARIES_H_

#include "Mesh.h"
#include "Node.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

// set boundaries - calls the setBoundary functions
void setBoundary(Mesh &mesh);

// set top boundary
void setBoundaryTop(Mesh &mesh);
// set bottom boundary
void setBoundaryBottom(Mesh &mesh);
// set left boundary
void setBoundaryLeft(Mesh &mesh);
// set right boundary
void setBoundaryRight(Mesh &mesh);

void setInnerNodes(Mesh &mesh);

#endif