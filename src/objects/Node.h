#ifndef NODE_H
#define NODE_H

#include <memory>

// node of the mesh
struct Node {
  size_t x, y;        // coordinates
  double temperature; // temperature
};

#endif // NODE_H