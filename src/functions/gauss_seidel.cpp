#include "Mesh.h"
#include "Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

void gaussSeidel(Mesh &mesh, const double tol, const size_t maxIterations) {
  double maxDifference{0.0};
  double oldTemperature;
  double newTemperature;
  size_t iterations{0};

  do {
    // iterating over the inner points
    for (auto i = 1u; i < mesh.numRows() - 1; ++i) {
      for (auto j = 1u; j < mesh.numCols() - 1; ++j) {
        oldTemperature = mesh.getNode(i, j);
        newTemperature = (mesh.getNode(i - 1, j) + mesh.getNode(i + 1, j) +
                          mesh.getNode(i, j - 1) + mesh.getNode(i, j + 1)) /
                         4;
        mesh.setNode(i, j, newTemperature);

        if (fabs(newTemperature - oldTemperature) > maxDifference) {
          maxDifference = abs(newTemperature - oldTemperature);
        }
      }
    }

    iterations++;

  } while (maxDifference > tol && iterations <= maxIterations);

  if (iterations >= maxIterations) {
    std::cout << "Maximum number of iterations reached without convergence \n"
              << std::endl;
    std::cout << "The accuracy is: " << maxDifference << std::endl;
  }
}
