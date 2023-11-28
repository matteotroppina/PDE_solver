
#include <iostream>
#include <memory>
#include <vector>

// Node - coordinates, temperature
struct Node {
  size_t x, y;
  double temperature;
};

using meshType = std::vector<std::vector<Node>>;

// Mesh
class Mesh {
private:
  std::unique_ptr<meshType> nodes; // pointer to a 2D vector of nodes

public:
  // constructor
  Mesh(const size_t width, const size_t height) {
    nodes = std::make_unique<meshType>(height, std::vector<Node>(width));
  }
};

int main() {

  size_t width, height;
  return 0;
}