#ifndef NODE_H
#define NODE_H

#include <memory>

// node of the mesh
struct Node {
  size_t x, y;        // coordinates
  double temperature; // temperature

  // Constructor that initializes temperature to 0
  Node() : temperature(0.0f) {}
};

#endif // NODE_H