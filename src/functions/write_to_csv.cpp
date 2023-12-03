#include "objects/Mesh.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

void printToCSV(Mesh &mesh, const std::string &filename) {
  std::ofstream file(filename + ".csv");

  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filename);
  }

  for (auto i = 0u; i < mesh.numRows(); ++i) {
    for (auto j = 0u; j < mesh.numCols() - 1; ++j) {
      file << mesh.getNode(i, j) << ", ";
    }
    file << mesh.getNode(i, mesh.numCols() - 1) << '\n';
  }

  file.close();
}