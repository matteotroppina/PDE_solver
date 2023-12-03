#include <iostream>
#include <limits>
#include <string>

namespace input {

size_t getRowsInput() {
  // Reading rows
  std::cout << "Mesh height (rows): ";
  while (true) {
    int temp;
    if (std::cin >> temp && temp > 0) {
      return static_cast<size_t>(temp);
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive integer "
                   "for rows.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Mesh height (rows): ";
    }
  }
}

size_t getColsInput() {
  std::cout << "Mesh width (columns): ";
  while (true) {
    int temp;
    if (std::cin >> temp && temp > 0) {
      return static_cast<size_t>(temp);
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive integer "
                   "for columns.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Mesh width (columns): ";
    }
  }
}

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

double getTolerance() {
  std::cout << "Specify the tolerance for the iterative method: ";
  while (true) {
    double temp;
    if (std::cin >> temp && temp > 0.0) {
      return temp;
    } else {
      std::cerr << "Warning: Invalid input. Please enter a positive number for "
                   "tolerance.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Specify the tolerance for the iterative method: ";
    }
  }
}

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

std::string getFileName() {
  std::string fileName;
  std::cout << "Enter the file name for output: ";
  std::cin >> fileName;
  return fileName;
}

} // namespace input