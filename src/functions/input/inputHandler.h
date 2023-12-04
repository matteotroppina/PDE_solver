#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#include <iostream>
#include <limits>
#include <string>

/**
 * @file Input.h
 * @brief Namespace for input-related functions.
 */

namespace input {

/**
 * @brief Reads and validates user input for mesh height (rows).
 * @return The number of rows as a size_t.
 */
size_t getRowsInput();

/**
 * @brief Reads and validates user input for mesh width (columns).
 * @return The number of columns as a size_t.
 */
size_t getColsInput();

/**
 * @brief Prompts for and validates the choice of iterative method.
 * @return The method choice as an unsigned integer (1 for Jacobi, 2 for
 * Gauss-Seidel).
 */
unsigned int getMethodChoice();

/**
 * @brief Reads and validates user input for the tolerance of the iterative
 * method.
 * @return The tolerance value as a double.
 */
double getTolerance();

/**
 * @brief Reads and validates user input for the maximum number of iterations.
 * @return The maximum number of iterations as a size_t.
 */
size_t getMaxIterations();

/**
 * @brief Reads user input for the filename.
 * @return The filename as a std::string.
 */
std::string getFileName();

} // namespace input

#endif