#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

/**
 * @class Parameters
 * @brief Manages the parameters for the Poisson heat equation solver.
 *
 * This class is responsible for initializing and storing all the parameters
 * needed for solving the Poisson heat equation. It includes grid dimensions,
 * boundary conditions, solver parameters, and file paths.
 */

class Parameters {
public:
  size_t rows;
  size_t cols;
  unsigned int method;
  double tolerance;
  size_t maxIterations;
  std::string fileName;
  std::string topBoundary;
  std::string bottomBoundary;
  std::string rightBoundary;
  std::string leftBoundary;
  double valueTop;
  double valueBottom;
  double valueRight;
  double valueLeft;

  /**
   * @brief Constructor for the Parameters class.
   * @param filePath The path to the file containing the parameters.
   *
   * Initializes the parameters to their default values and then reads the
   * parameters from a given file. The file should contain key-value pairs
   * for various parameters like grid dimensions, solver settings, and boundary
   * conditions. The format of the file is expected to be CSV with keys and
   * values.
   */

  Parameters(const std::string &filePath);

private:
  /**
   * @brief Reads and sets parameters from a file.
   * @param filePath The path to the file containing the parameters.
   *
   * Opens the specified file and reads the key-value pairs for various
   * parameters. It supports parameters for grid dimensions, numerical method,
   * tolerance, maximum iterations, output file, and boundary conditions.
   * The method throws an exception if the file cannot be opened or if
   * unrecognized keys are encountered.
   */
  void readParametersFromFile(const std::string &filePath);

  /**
   * @brief Prints the current set of parameters to the standard output.
   *
   * Outputs the current set of parameters including grid dimensions, numerical
   * method, tolerance, maximum iterations, output file name, and boundary
   * conditions. This is useful for debugging and verification purposes to
   * ensure that the parameters are correctly set.
   */
  void printParameters();
};

#endif