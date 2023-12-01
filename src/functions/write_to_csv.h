#ifndef _WRITE_TO_CSV_H_
#define _WRITE_TO_CSV_H_

#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

void printToCSV(Mesh &mesh, const std::string &filename);

#endif