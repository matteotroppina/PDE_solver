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
  size_t rows, cols;
  meshType currentGrid; // pointer to a 2D vector of nodes
  meshType newGrid;     // second layer for Jacobi method

public:
  /**
   * @brief Construct a new Mesh object.
   *
   * @param rows The number of rows in the mesh.
   * @param cols The number of columns in the mesh.
   * @throws std::runtime_error If grid allocation fails.
   */
  // constructor

  void checkGrid();

  Mesh(const size_t rows, const size_t cols);

  /**
   * @brief Gets the temperature value at a specific node.
   *
   * @param x Row index of the node.
   * @param y Column index of the node.
   * @return The temperature value at the node.
   */

  const double getNode(const size_t x, const size_t y);

  /**
   * @brief Sets the temperature value of a specified node.
   *
   * @param x The row index of the node.
   * @param y The column index of the node.
   * @param temperatureValue The temperature value to set at the node.
   */

  void setNode(const size_t x, const size_t y, const double temperatureValue);

  /**
   * @brief Updates the temperature of a node to a new value.
   *
   * @param x The row index of the node.
   * @param y The column index of the node.
   * @param newTemperature The new temperature value for the node.
   */

  void setNew(const size_t x, const size_t y, const double newTemperature);

  /**
   * @brief Returns the number of rows in the mesh.
   *
   * @return The number of rows.
   */

  const size_t numRows();

  /**
   * @brief Returns the number of columns in the mesh.
   *
   * @return The number of columns.
   */
  const size_t numCols();

  /**
   * @brief Swaps the two mesh layers for the Jacobi method.
   *
   */
  void swapGrids();
};

#endif