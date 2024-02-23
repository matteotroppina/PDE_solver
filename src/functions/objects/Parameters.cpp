#include "Parameters.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

Parameters::Parameters(const std::string &filePath)
    : rows(0), cols(0), method(0), tolerance(0.0), maxIterations(0),
      fileName(""), topBoundary(""), bottomBoundary(""), rightBoundary(""),
      leftBoundary(""), valueTop(0.0), valueBottom(0.0), valueLeft(0.0),
      valueRight(0.0) {
  std::cout << "Uploading the parameters..." << std::endl;
  readParametersFromFile(filePath);
}

void Parameters::readParametersFromFile(const std::string &filePath) {

  std::cout << "Reading the file...\n" << std::endl;
  std::ifstream file(filePath);
  if (!file) {
    throw std::runtime_error("Unable to open file: " + filePath);
  }

  std::string line;

  while (std::getline(file, line)) {
    std::istringstream lineStream(line);
    std::string key, value1, value2;
    std::getline(lineStream, key, ',');
    std::getline(lineStream, value1, ',');
    std::getline(lineStream, value2);

    if (key == "rows") {
      rows = std::stoul(value1);
    } else if (key == "columns") {
      cols = std::stoul(value1);
    } else if (key == "method") {
      method = std::stoul(value1);
    } else if (key == "tolerance") {
      tolerance = std::stod(value1);
    } else if (key == "maxIterations") {
      maxIterations = std::stoul(value1);
    } else if (key == "outputFile") {
      fileName = value1;
    } else if (key == "topBoundary") {
      topBoundary = value1;
      valueTop = !value2.empty() ? std::stod(value2) : 0.0;
    } else if (key == "bottomBoundary") {
      bottomBoundary = value1;
      valueBottom = !value2.empty() ? std::stod(value2) : 0.0;
    } else if (key == "rightBoundary") {
      rightBoundary = value1;
      valueRight = !value2.empty() ? std::stod(value2) : 0.0;
    } else if (key == "leftBoundary") {
      leftBoundary = value1;
      valueLeft = !value2.empty() ? std::stod(value2) : 0.0;
    } else {
      throw std::runtime_error("Unrecognized key in parameters file: " + key);
    }
  }
  printParameters();
}

void Parameters::printParameters() {

  std::cout << "Rows: " << rows << std::endl;
  std::cout << "Columns: " << cols << std::endl;
  std::cout << "Method: " << method << std::endl;
  std::cout << "Tolerance: " << tolerance << std::endl;
  std::cout << "Max Iterations: " << maxIterations << std::endl;
  std::cout << "Output File: " << fileName << '\n' << std::endl;
  std::cout << "Top Boundary --> " << topBoundary << " (Value: " << valueTop
            << ')' << std::endl;
  std::cout << "Bottom Boundary --> " << bottomBoundary
            << " (Value: " << valueBottom << ')' << std::endl;
  std::cout << "Left Boundary --> " << leftBoundary << " (Value: " << valueLeft
            << ')' << std::endl;
  std::cout << "Right Boundary --> " << rightBoundary
            << " (Value: " << valueRight << ')' << '\n'
            << std::endl;
}