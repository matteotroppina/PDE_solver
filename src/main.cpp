
#include "functions/Mesh.h"
#include "functions/Node.h"
#include "functions/boundaries.h"
#include "functions/inputHandler.h"
#include "functions/jacobi.h"
#include "functions/write_to_csv.h"
#include "gauss_seidel.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

  size_t rows{0}, cols{0};
  unsigned int methodChoice;
  double tol{0.0};
  size_t maxIterations{0};
  std::string filename;

  // mesh initialization
  std::cout << "** Mesh Initialization **\n";
  rows = input::getRowsInput();
  cols = input::getColsInput();
  Mesh myMesh(rows, cols);

  // iterative method choice
  methodChoice = input::getMethodChoice();

  // set tolerance
  tol = input::getTolerance();

  // set iterations limit for the chosen iterative method
  maxIterations = input::getMaxIterations();

  setBoundary(myMesh);
  myMesh.printMesh(rows, cols);

  if (methodChoice == 1) {
    jacobi(myMesh, tol, maxIterations);
  } else {
    gaussSeidel(myMesh, tol, maxIterations);
  }

  // set the output filename
  filename = input::getFileName();
  printToCSV(myMesh, filename);

  return 0;
}