#include "functions/input/boundaries.h"
#include "functions/input/inputHandler.h"
#include "functions/methods/gauss_seidel.h"
#include "functions/methods/jacobi.h"
#include "functions/objects/Mesh.h"
#include "functions/objects/Node.h"
#include "functions/write_to_csv.h"
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

  // set tolerance for the chosen iterative method
  tol = input::getTolerance();

  // set iterations limit for the chosen iterative method
  maxIterations = input::getMaxIterations();

  setDirichletBoundaries(myMesh);
  myMesh.printMesh(rows, cols);

  if (methodChoice == 1) {
    jacobi(myMesh, tol, maxIterations);
  } else {
    gaussSeidel(myMesh, tol, maxIterations);
  }

  // set the output filename.csv
  filename = input::getFileName();
  printToCSV(myMesh, filename);

  return 0;
}