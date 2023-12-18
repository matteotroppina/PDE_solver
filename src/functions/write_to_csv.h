#ifndef _WRITE_TO_CSV_H_
#define _WRITE_TO_CSV_H_

#include "objects/Mesh.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

/**
 * @file write_to_csv.h
 * @brief Function to print mesh data to a CSV file.
 */

/**
 * @brief Prints the data of a Mesh object to a CSV file.
 *
 * This function exports the data contained in a Mesh object into a CSV file.
 * Each row of the mesh is written as a row in the CSV file, with values
 * separated by commas.
 *
 * @param mesh The Mesh object to be printed.
 * @param filename The name of the file to which the Mesh data will be printed.
 * @throws std::runtime_error if the file cannot be opened.
 */
void printToCSV(Mesh &mesh, const std::string &filename);

#endif