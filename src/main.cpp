
#include <iostream>
#include <memory>
#include <vector>

struct Node {
  size_t x, y;
  double temperature;
};

using meshType = std::vector<std::vector<Node>>;

class Mesh {
private:
  std::unique_ptr<meshType> nodes; // pointer to a 2D vector of nodes

public:
  // constructor
  Mesh(const size_t width, const size_t height) {
    nodes = std::make_unique<meshType>(height, std::vector<Node>(width));
  }

  // method .getNode(x,y)
  // return the a pointer to the (x,y) node
  Node Mesh::getNode(const size_t x, const size_t y) {
    return (*nodes).at(x).at(y);
  };
};

int main() {

  // mesh initialization
  size_t height; // rows
  size_t width;  // columns

  std::cout << "** Mesh Initialization ** \n";
  std::cout << "Mesh height (rows):" << std::endl;
  std::cin >> height;
  std::cout << "Mesh width (columns):" << std::endl;
  std::cin >> width;

  Mesh myMesh(width, height);

  return 0;
}