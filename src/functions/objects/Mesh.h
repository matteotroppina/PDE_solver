#ifndef _MESH_H
#define _MESH_H

#include "Node.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using meshType = std::vector<std::vector<Node>>;
class Mesh {
private:
  std::unique_ptr<meshType> nodes; // pointer to a 2D vector of nodes
  size_t rows, cols;

public:
  // constructor
  Mesh(const size_t rows, const size_t cols);

  // method .getNode(x,y)
  // return the a pointer to the (x,y) node
  const double getNode(const size_t x, const size_t y);

  // method .setNode(x,y,value)
  // set the temperature value of the node
  void setNode(const size_t x, const size_t y, const double temperatureValue);

  void setNew(const size_t x, const size_t y, const double newTemperature);

  const size_t numRows();

  const size_t numCols();

  void printMesh(const size_t rows, const size_t cols);

  void updateTemperature();
};

#endif