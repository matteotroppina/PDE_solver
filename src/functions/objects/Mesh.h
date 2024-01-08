#ifndef _MESH_H
#define _MESH_H

#include "Node.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using meshType = std::vector<std::vector<Node>>;

/**
 * @file Mesh.h
 * @brief Class for representing a 2D grid of nodes.
 */

/**
 * @class Mesh
 * @brief Represents a 2D grid of nodes in a mesh.
 *
 * The Mesh class stores a grid of nodes, each holding temperature data.
 * It provides methods for accessing and modifying these nodes.
 */
class Mesh {
private:
  std::unique_ptr<meshType> currentGrid; // pointer to a 2D vector of nodes
  size_t rows, cols;

public:
  /**
   * @brief Construct a new Mesh object.
   *
   * Creates a mesh with the specified number of rows and columns.
   * Throws a runtime_error if the grid allocation fails.
   *
   * @param rows The number of rows in the mesh.
   * @param cols The number of columns in the mesh.
   * @throws std::runtime_error If grid allocation fails.
   */
  // constructor
  Mesh(const size_t rows, const size_t cols);

  const double getNode(const size_t x, const size_t y);

  void setNode(const size_t x, const size_t y, const double temperatureValue);

  void setNew(const size_t x, const size_t y, const double newTemperature);

  const size_t numRows();

  const size_t numCols();

  void printMesh(const size_t rows, const size_t cols);

  void updateTemperature();
};

#endif