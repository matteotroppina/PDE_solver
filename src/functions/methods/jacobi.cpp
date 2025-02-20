#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Implementation of the Jacobi iterative method.
 */
void jacobi(Mesh &mesh, const double tol, const size_t maxIterations) {
  double maxDifference{0.0};
  size_t iterations{0};

  auto rows = mesh.numRows();
  auto cols = mesh.numCols();

  do {
    maxDifference = 0.0; // Reset maxDifference for each iteration
    for (auto i = 1u; i < rows - 1; ++i) {
      for (auto j = 1u; j < cols - 1; ++j) {

        double newTemperature =
            (mesh.getNode(i - 1, j) + mesh.getNode(i + 1, j) +
             mesh.getNode(i, j - 1) + mesh.getNode(i, j + 1)) /
            4;

        double tempDifference = std::fabs(newTemperature - mesh.getNode(i, j));

        if (tempDifference > maxDifference) {
          maxDifference = tempDifference;
        }

        mesh.setNew(i, j, newTemperature);
      }
    }

    mesh.swapGrids(); // swaps the two layers
    iterations++;

    // Check for early convergence
    if (maxDifference <= tol) {
      break;
    }

  } while (iterations <= maxIterations);

  if (iterations >= maxIterations) {
    std::cout << "Maximum number of iterations reached without convergence \n";
    std::cout << "The accuracy is: " << maxDifference << std::endl;
  } else {
    std::cout << "Convergence reached in " << iterations << " iterations"
              << '\n';
    std::cout << "The accuracy is: " << maxDifference << std::endl;
  }
}
