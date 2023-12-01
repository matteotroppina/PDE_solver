
#include "functions/Mesh.h"
#include "functions/Node.h"
#include "functions/boundaries.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

  // mesh initialization
  size_t rows;
  size_t cols; // columns

  std::cout << "** Mesh Initialization ** \n";
  std::cout << "Mesh height (rows):";
  std::cin >> rows;
  std::cout << "Mesh width (columns):";
  std::cin >> cols;

  Mesh myMesh(rows, cols);
  // std::cout << myMesh.numRows() << " " << myMesh.numCols() << '\n';
  setBoundary(myMesh);
  myMesh.printMesh(rows, cols);

  return 0;
}