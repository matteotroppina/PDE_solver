#include "boundaries.h"
#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include "../objects/Parameters.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

Boundaries::Boundaries(Mesh &myMesh, Parameters &params)
    : _myMesh(myMesh), _myParameters(params) {
  setBottom();
  setTop();
  setRight();
  setLeft();
  setInnerNodes();
  std::cout << "Grid is initialized\n" << std::endl;
}

void Boundaries::setTop() {
  size_t i = 0;
  for (size_t j = 0; j < _myMesh.numCols(); ++j) {
    _myMesh.setNode(i, j,
                    getFunction(_myParameters.topBoundary,
                                _myParameters.valueTop, i, j,
                                _myMesh.numCols()));
  }
}

void Boundaries::setBottom() {
  size_t i = _myMesh.numCols() - 1;
  for (size_t j = 0; j < _myMesh.numCols(); ++j) {
    _myMesh.setNode(i, j,
                    getFunction(_myParameters.bottomBoundary,
                                _myParameters.valueBottom, i, j,
                                _myMesh.numCols()));
  }
}

void Boundaries::setLeft() {
  size_t j = 0;
  for (size_t i = 1; i < _myMesh.numRows() - 1; ++i) {
    _myMesh.setNode(i, j,
                    getFunction(_myParameters.leftBoundary,
                                _myParameters.valueLeft, i, j,
                                _myMesh.numRows()));
  }
}

void Boundaries::setRight() {
  size_t j = _myMesh.numCols() - 1;
  for (size_t i = 1; i < _myMesh.numRows() - 1; ++i) {
    _myMesh.setNode(i, j,
                    getFunction(_myParameters.rightBoundary,
                                _myParameters.valueRight, i, j,
                                _myMesh.numRows()));
  }
}

double Boundaries::getFunction(const std::string &boundaryFunction,
                               double value, size_t i, size_t j,
                               size_t length) {

  const double dx = 1.0 / (_myMesh.numCols() - 1);
  const double dy = 1.0 / (_myMesh.numRows() - 1);

  if (boundaryFunction == "constant") {

    return value;

  } else if (boundaryFunction == "sinusoidal") {

    return value * std::sin(i + j);

  } else if (boundaryFunction == "testfunction") {
    double x = j * dx;
    double y = i * dy;

    return 1 + x * x + 2 * y * y;
  }

  return 0.0; // Default return value if no condition matches
}

void Boundaries::setInnerNodes() {
  for (auto i = 1u; i < _myMesh.numRows() - 1; ++i) {
    for (auto j = 1u; j < _myMesh.numCols() - 1; ++j) {

      // Interpolate along rows (left and right boundaries)
      double leftValue = _myMesh.getNode(i, 0);
      double rightValue = _myMesh.getNode(i, _myMesh.numCols() - 1);
      double rowInterpolation =
          leftValue + (rightValue - leftValue) * j / (_myMesh.numCols() - 1);

      // Interpolate along columns (top and bottom boundaries)
      double topValue = _myMesh.getNode(0, j);
      double bottomValue = _myMesh.getNode(_myMesh.numRows() - 1, j);
      double columnInterpolation =
          topValue + (bottomValue - topValue) * i / (_myMesh.numRows() - 1);

      // Average the two interpolated values
      double meanValue = (rowInterpolation + columnInterpolation) / 2.0;
      _myMesh.setNode(i, j, meanValue);
    }
  }
}
