#include "Mesh.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

/**
 * @brief Constructs a Mesh object.
 *
 * Initializes a Mesh object with specified rows and columns. Allocates memory
 * for the nodes and checks for successful allocation.
 *
 * @param rows The number of rows in the mesh.
 * @param cols The number of columns in the mesh.
 * @throw std::runtime_error If memory allocation for the grid fails.
 *//**
 * @brief Implementation of Mesh constructor.
 */
Mesh::Mesh(const size_t rows, const size_t cols)
    : rows(rows), cols(cols),
      nodes(std::make_unique<meshType>(rows, std::vector<Node>(cols))) {

  // Check if the grid is allocated
  if ((*nodes).empty() || (*nodes).at(0).empty()) {
    throw std::runtime_error("Grid allocation failed");
  }
}

/**
 * @brief Gets the temperature value at a specific node.
 *
 * @param x Row index of the node.
 * @param y Column index of the node.
 * @return The temperature value at the node.
 */
const double Mesh::getNode(const size_t x, const size_t y) {
  const Node &currentNode = nodes->at(x).at(y);
  return currentNode.temperature;
}

/**
 * @brief Sets the temperature value of a specified node.
 *
 * @param x The row index of the node.
 * @param y The column index of the node.
 * @param temperatureValue The temperature value to set at the node.
 */
void Mesh::setNode(const size_t x, const size_t y,
                   const double temperatureValue) {
  Node &currentNode = nodes->at(x).at(y);
  currentNode.temperature = temperatureValue;
}

/**
 * @brief Updates the temperature of a node to a new value.
 *
 * @param x The row index of the node.
 * @param y The column index of the node.
 * @param newTemperature The new temperature value for the node.
 */
void Mesh::setNew(const size_t x, const size_t y, const double newTemperature) {
  Node &currentNode = nodes->at(x).at(y);
  currentNode.newTemperature = newTemperature;
}

/**
 * @brief Returns the number of rows in the mesh.
 *
 * @return The number of rows.
 */
const size_t Mesh::numRows() { return nodes->size(); }

/**
 * @brief Returns the number of columns in the mesh.
 *
 * @return The number of columns.
 */
const size_t Mesh::numCols() { return nodes->at(0).size(); }

void Mesh::printMesh(const size_t rows, const size_t cols) {
  for (auto i = 0u; i < rows; ++i) {
    for (auto j = 0u; j < cols; ++j) {
      std::cout << nodes->at(i).at(j).temperature << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Swaps the current and new temperatures of each node.
 *
 * Iterates over the mesh, excluding the boundary, and swaps the current
 * temperature with the new temperature for each node.
 */
void Mesh::updateTemperature() {
  for (auto i = 1u; i < rows - 1; i++) {
    for (auto j = 1u; j < cols - 1; j++) {
      std::swap(nodes->at(i).at(j).temperature,
                nodes->at(i).at(j).newTemperature);
    }
  }
}
