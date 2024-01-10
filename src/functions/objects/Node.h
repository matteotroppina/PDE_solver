#ifndef NODE_H
#define NODE_H

#include <memory>

/**
 * @file Node.h
 * @brief Defines the Node struct used in a mesh.
 */

/**
 * @struct Node
 * @brief  Represents a node in a mesh.
 *
 * This struct is used to represent a single node within a mesh.
 * Each node holds its temperature values.
 */
struct Node {
  double temperature; ///< The current temperature at the node.

  /**
   * @brief Constructor for Node.
   *
   * Initializes a Node with a default temperature of 0.0.
   */
  Node() : temperature(0.0) {}
};

#endif // NODE_H