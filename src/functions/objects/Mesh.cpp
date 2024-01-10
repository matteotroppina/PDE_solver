#include "Mesh.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

Mesh::Mesh(const size_t rows, const size_t cols)
    : rows(rows), cols(cols),
      currentGrid(meshType(rows, std::vector<Node>(cols))),
      newGrid(meshType(rows, std::vector<Node>(cols))) {

  // Check if the grid is allocated
  if ((currentGrid).empty() || (currentGrid).at(0).empty()) {
    throw std::runtime_error("First Grid allocation failed");
  }
  // Check if the grid is allocated
  if ((newGrid).empty() || (newGrid).at(0).empty()) {
    throw std::runtime_error("Second Grid allocation failed");
  }
}

const double Mesh::getNode(const size_t x, const size_t y) {
  return currentGrid.at(x).at(y).temperature;
}

void Mesh::setNode(const size_t x, const size_t y,
                   const double temperatureValue) {
  currentGrid.at(x).at(y).temperature = temperatureValue;
}

void Mesh::setNew(const size_t x, const size_t y, const double newTemperature) {
  newGrid.at(x).at(y).temperature = newTemperature;
}

const size_t Mesh::numRows() { return currentGrid.size(); }

const size_t Mesh::numCols() { return currentGrid.at(0).size(); }

void Mesh::swapGrids() { std::swap(currentGrid, newGrid); }
