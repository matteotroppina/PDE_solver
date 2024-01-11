#include "../tests/jacobiTest.h"
#include "functions/methods/gauss_seidel.h"
#include "functions/methods/jacobi.h"
#include "functions/objects/Mesh.h"
#include "functions/objects/Node.h"
#include "functions/objects/Parameters.h"
#include "functions/objects/boundaries.h"
#include "functions/write_to_csv.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

int main(int argc, char *argv[]) {

  if (argc > 1 && std::string(argv[1]) == "--test") {
    // Run the test function if the "--test" argument is passed
    std::cout << "Running Jacobi test...\n"; // Debugging line
    if (testJacobi()) {
      std::cout << "Jacobi test passed." << std::endl;
      return 0;
    } else {
      std::cerr << "Jacobi test failed." << std::endl;
      return -1;
    }
  } else {

    std::string filePath;
    std::cout << "Provide the path to the parameters file(.txt): ";
    std::cin >> filePath;
    std::cout << std::endl;

    try {
      Parameters parameters(filePath);

      Mesh myMesh(parameters.rows, parameters.cols);
      Boundaries(myMesh, parameters);

      if (parameters.method == 1) {
        jacobi(myMesh, parameters.tolerance, parameters.maxIterations);
      } else {
        gaussSeidel(myMesh, parameters.tolerance, parameters.maxIterations);
      }
      // set the output filename.csv
      printToCSV(myMesh, parameters.fileName);

    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  return 0;
}
