#ifndef _MESH_H
#define _MESH_H

#include "Node.h"
#include <memory>
#include <vector>

using meshType = std::vector<std::vector<Node>>;
class Mesh {
private:
  std::unique_ptr<meshType> nodes; // pointer to a 2D vector of nodes

public:
  // constructor
  Mesh(const size_t width, const size_t height);

  // method .getNode(x,y)
  // return the a pointer to the (x,y) node
  Node &getNode(const size_t x, const size_t y);

  // method .printMesh()
  // print the temperature values of the nodes
  void printMesh(const size_t width, const size_t height);
};

#endif