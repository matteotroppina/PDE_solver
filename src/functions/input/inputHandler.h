#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#include <iostream>
#include <limits>
#include <string>

namespace input {

size_t getRowsInput();

size_t getColsInput();

unsigned int getMethodChoice();

double getTolerance();

size_t getMaxIterations();

std::string getFileName();

} // namespace input

#endif