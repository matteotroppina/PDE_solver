
#include "functions/Mesh.h"
#include "functions/Node.h"
#include "functions/boundaries.h"
#include "functions/jacobi.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

  // mesh initialization
  size_t rows{0};
  size_t cols{0};
  double tol{0.0};
  size_t maxIterations{0};

  std::cout << "** Mesh Initialization ** \n";
  std::cout << "Mesh height (rows):";
  std::cin >> rows;
  std::cout << "Mesh width (columns):";
  std::cin >> cols;
  std::cout << std::endl;

  Mesh myMesh(rows, cols);
  // std::cout << myMesh.numRows() << " " << myMesh.numCols() << '\n';
  setBoundary(myMesh);
  // myMesh.printMesh(rows, cols);

  std::cout << "Specify the tolerance for the iterative method: ";
  std::cin >> tol;
  std::cout
      << "Specify the max number of iterations for the iterative method: ";
  std::cin >> maxIterations;
  jacobi(myMesh, tol, maxIterations);

  myMesh.printMesh(rows, cols);

  return 0;
}