#include "inputHandler.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace input {

/**
 * @brief  Implementation of getRowsInput.
 * @return The number of rows as a size_t
 * @throws Invalid Input
 */
size_t getRowsInput() {
  // Reading rows
  std::cout << "Mesh height (rows): ";
  while (true) {
    double rows;
    if (std::cin >> rows && rows > 0 && std::floor(rows) == rows) {
      return static_cast<size_t>(rows);
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive integer "
                   "for rows.\n";
      std::cin.clear(); // Reset the error flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Mesh height (rows): ";
    }
  }
}

/**
 * @brief  Implementation of getColsInput.
 * @return The number of columns as size_t
 * @throws Invalid Input
 */
size_t getColsInput() {
  std::cout << "Mesh width (columns): ";
  while (true) {
    double cols;
    if (std::cin >> cols && cols > 0 && std::floor(cols) == cols) {
      return static_cast<size_t>(cols);
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive integer "
                   "for columns.\n";
      std::cin.clear(); // Reset the error flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Mesh width (columns): ";
    }
  }
}

/**
 * @brief  Implementation of getMethodChoice.
 * @return The method choice as an unsigned integer (1 for Jacobi, 2 for
 Gauss-Seidel).
 * @throws Invalid Input
 */
unsigned int getMethodChoice() {
  unsigned int choice;
  while (true) {
    std::cout << "Iterative method choice:\n"
              << "(1) Jacobi method\n"
              << "(2) Gauss-Seidel method\n"
              << "Enter choice (1 or 2): ";
    if (std::cin >> choice && (choice == 1 || choice == 2)) {
      return choice;
    } else {
      std::cerr << "Invalid input. Please enter 1 for Jacobi or 2 for "
                   "Gauss-Seidel.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/**
 * @brief  Implementation of getTolerance.
 * @return The tolerance value as a double.
 * @throws Invalid Input
 */
double getTolerance() {
  std::cout << "Specify the tolerance for the iterative method: ";
  while (true) {
    double tol;
    if (std::cin >> tol && tol > 0.0) {
      return tol;
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive number for "
                   "tolerance.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Specify the tolerance for the iterative method: ";
    }
  }
}

/**
 * @brief  Reads and validates user input for the maximum number of iterations.
 * @return The maximum number of iterations as a size_t.
 * @throws Invalid Input
 */
size_t getMaxIterations() {
  int maxIterations;
  while (true) {
    std::cout << "Enter the maximum number of iterations: ";
    if (std::cin >> maxIterations && maxIterations > 0) {
      return static_cast<size_t>(maxIterations);
    } else {
      std::cerr << "Invalid input. Please enter a positive integer.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/**
 * @brief  Reads user input for the filename.
 * @return The filename as a std::string.
 */
std::string getFileName() {
  std::string fileName;
  std::cout << "Enter the file name for output: ";
  std::cin >> fileName;
  return fileName;
}

} // namespace input