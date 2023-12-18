#ifndef _BOUNDARIES_H_
#define _BOUNDARIES_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <vector>

/**
 * @file boundaries.h
 * @brief Functions to set boundary conditions on a mesh.
 */

/**
 * @brief Prompts for and returns a boundary value.
 * @param prompt The prompt message.
 * @return The boundary value.
 */
double getBoundary(const std::string &prompt);

/**
 * @brief Sets a boundary temperature on the mesh.
 * @param mesh The mesh to modify.
 * @param boundary The boundary to set.
 */
void setBoundary(Mesh &mesh, const std::string &boundary);

/**
 * @brief Sets a boundary temperature on the mesh for testing.
 * @param mesh The mesh to modify.
 * @param boundary The boundary to set.
 * @param temperatureValue Boundary temperature value
 */
void setBoundary(Mesh &mesh, const std::string &boundary,
                 double temperatureValue);

/**
 * @brief Sets the inner nodes of a mesh based on boundary values.
 * @param mesh The mesh to modify.
 */
void setInnerNodes(Mesh &mesh);

/**
 * @brief Sets Dirichlet boundaries on all sides of the mesh.
 * @param mesh The mesh to modify.
 */
void setDirichletBoundaries(Mesh &mesh);

#endif