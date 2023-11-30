#ifndef _BOUNDARIES_H_
#define _BOUNDARIES_H_

#include "Mesh.h"
#include "Node.h"
#include <iostream>
#include <memory>
#include <vector>

void setBoundary(Mesh &mesh);

void setBoundaryTop(Mesh &mesh);
void setBoundaryBottom(Mesh &mesh);
void setBoundaryLeft(Mesh &mesh);
void setBoundaryRight(Mesh &mesh);

#endif