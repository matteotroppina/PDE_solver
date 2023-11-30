#include "Mesh.h"
#include <memory>
#include <stdexcept>
#include <vector>

// constructor
Mesh::Mesh(const size_t width, const size_t height) {
  nodes = std::make_unique<meshType>(height, std::vector<Node>(width));

  // Check if the grid is allocated
  if ((*nodes).empty() || (*nodes).at(0).empty()) {
    throw std::runtime_error("Grid allocation failed");
  }
}

// method .getNode(x,y)
// return the temperature value at the (x,y) node
const double Mesh::getNode(const size_t x, const size_t y) {
  const Node &currentNode = nodes->at(x).at(y);
  return currentNode.temperature;
}

// method .setNode(x,y,value)
// set the temperature value of the (x,y) node
void Mesh::setNode(const size_t x, const size_t y,
                   const double temperatureValue) {
  Node &currentNode = nodes->at(x).at(y);
  currentNode.temperature = temperatureValue;
}

const size_t Mesh::getRows() { return nodes->size(); }

const size_t Mesh::getCols() { return nodes->at(0).size(); }
