#include "write_to_csv.h"
#include "objects/Mesh.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

void printToCSV(Mesh &mesh, const std::string &filename) {
  std::ofstream file(filename + ".csv");

  // Throw runtime_error if the file cannot be opened
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filename);
  }

  // Loop through the mesh and write each node's value to the CSV file
  auto cols = mesh.numCols();
  auto rows = mesh.numRows();
  for (auto i = 0u; i < rows; ++i) {
    for (auto j = 0u; j < cols - 1; ++j) {
      file << mesh.getNode(i, j) << ", ";
    }
    file << mesh.getNode(i, cols - 1) << '\n';
  }

  file.close();
}