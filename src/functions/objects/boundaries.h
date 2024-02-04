#ifndef _BOUNDARIES_H_
#define _BOUNDARIES_H_

#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include "../objects/Parameters.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

class Boundaries {
private:
  Mesh &_myMesh;
  Parameters &_myParameters;
  size_t _rows, _cols;

  /**
   * Sets the top boundary of the mesh based on the specified boundary
   * conditions. The function iterates over the top row of the mesh and applies
   * the boundary condition function to each node.
   */

  void setTop();

  /**
   * Sets the bottom boundary of the mesh based on the specified boundary
   * conditions. The function iterates over the bottom row of the mesh and
   * applies the boundary condition function to each node.
   */

  void setBottom();

  /**
   * Sets the right boundary of the mesh based on the specified boundary
   * conditions. The function iterates over the right column of the mesh
   * (excluding the top and bottom nodes) and applies the boundary condition
   * function to each node.
   */

  void setRight();

  /**
   * Sets the left boundary of the mesh based on the specified boundary
   * conditions. The function iterates over the left column of the mesh
   * (excluding the top and bottom nodes) and applies the boundary condition
   * function to each node.
   */

  void setLeft();

  /**
   * Sets the values for the inner nodes of the mesh. This function interpolates
   * values between the already set boundaries to fill in the inner nodes of the
   * mesh. It performs interpolation both along the rows and columns and then
   * averages these values to determine the final value for each inner node.
   */

  void setInnerNodes();

  /**
   * Determines the value to be set at a boundary node based on the specified
   * boundary function and other parameters.
   *
   * @param boundaryFunction The name of the boundary condition function.
   * @param value The value associated with the boundary condition.
   * @param i Row index of the node in the mesh.
   * @param j Column index of the node in the mesh.
   * @param length The dimension of the mesh along the current boundary.
   * @return The calculated value for the boundary node.
   */

  double getFunction(const std::string &boundaryFunction, double value,
                     size_t i, size_t j, size_t length);

public:
  /**
   * Constructs the Boundaries object, initializing the mesh and parameters,
   * and setting up boundary conditions for all sides of the mesh.
   *
   * @param myMesh Reference to the Mesh object.
   * @param params Reference to the Parameters object.
   */
  Boundaries(Mesh &myMesh, Parameters &params);
};

#endif