
#include "functions/Mesh.h"
#include "functions/Node.h"
#include "functions/boundaries.h"
#include "functions/jacobi.h"
#include "functions/write_to_csv.h"
#include "gauss_seidel.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

  // mesh initialization
  size_t rows{0};
  size_t cols{0};
  double tol{0.0};
  size_t maxIterations{0};
  std::string filename;
  unsigned int methodChoice;

  std::cout << "** Mesh Initialization ** \n";
  std::cout << "Mesh height (rows):";
  std::cin >> rows;
  std::cout << "Mesh width (columns):";
  std::cin >> cols;
  std::cout << std::endl;

  Mesh myMesh(rows, cols);
  setBoundary(myMesh);

  std::cout << "Specify the tolerance for the iterative method: ";
  std::cin >> tol;
  std::cout
      << "Specify the max number of iterations for the iterative method: ";
  std::cin >> maxIterations;

  std::cout << "Iterative method choice: \n"
            << "(1) Jacobi method \n"
            << "(2) Gauss-Seidel method \n"
            << "(1/2): ";
  std::cin >> methodChoice;

  if (methodChoice == 1) {
    jacobi(myMesh, tol, maxIterations);
  } else {
    gaussSeidel(myMesh, tol, maxIterations);
  }

  std::cout << "Specify the CSV file name (.csv): ";
  std::cin >> filename;

  jacobi(myMesh, tol, maxIterations);
  printToCSV(myMesh, filename);

  myMesh.printMesh(rows, cols);

  return 0;
}