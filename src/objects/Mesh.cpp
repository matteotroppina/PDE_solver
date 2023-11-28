#include "Mesh.h"
#include <memory>
#include <vector>

// constructor
Mesh::Mesh(const size_t width, const size_t height) {
  nodes = std::make_unique<meshType>(height, std::vector<Node>(width));
}

// method .getNode(x,y)
// return the a pointer to the (x,y) node
Node &Mesh::getNode(const size_t x, const size_t y) {
  return nodes->at(x).at(y);
}
