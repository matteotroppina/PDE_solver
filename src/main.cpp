
#include "functions/Mesh.h"
#include "functions/Node.h"
#include "functions/boundaries.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

  // mesh initialization
  size_t height; // rows
  size_t width;  // columns

  std::cout << "** Mesh Initialization ** \n";
  std::cout << "Mesh height (rows):";
  std::cin >> height;
  std::cout << "Mesh width (columns):";
  std::cin >> width;

  Mesh myMesh(width, height);
  setBoundary(myMesh);

  return 0;
}