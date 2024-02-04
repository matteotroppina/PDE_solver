#include "../src/functions/methods/jacobi.h"
#include "../src/functions/objects/Mesh.h"
#include "../src/functions/objects/Node.h"
#include "../src/functions/objects/Parameters.h"
#include "../src/functions/objects/boundaries.h"
#include "../src/functions/write_to_csv.h"
#include "jacobiTest.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

bool testJacobi() {

  try {
    Parameters parameters("../tests/test.csv");

    Mesh myMesh(parameters.rows, parameters.cols);
    Boundaries(myMesh, parameters);
    jacobi(myMesh, parameters.tolerance, parameters.maxIterations);
    printToCSV(myMesh, parameters.fileName);

    auto rows = myMesh.numRows();
    auto cols = myMesh.numCols();

    const double dx = 1.0 / (rows - 1);
    const double dy = 1.0 / (cols - 1);

    for (size_t i = 1; i < rows - 1; ++i) {
      for (size_t j = 1; j < cols - 1; ++j) {
        double x = j * dx;
        double y = i * dy;
        if (std::fabs(myMesh.getNode(i, j) - (1 + x * x + 2 * y * y)) >
            parameters.tolerance) {
          return false;
        }
      }
    }

    return true;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}