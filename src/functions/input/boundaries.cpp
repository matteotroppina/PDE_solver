#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

void setBoundaryTop(Mesh &mesh) {
  int choice = -1;
  int temperatureValue;
  std::cout << "Set Top Boundary conditions: \n"
            << "(1) Dirichlet boundary conditions \n"
            << "(2) Neumann boundary conditions \n";
  std::cout << ">> ";
  std::cin >> choice;
  std::cout << "Set temperature value T[top,:]: ";
  std::cin >> temperatureValue;
  for (auto j = 0u; j < mesh.numCols(); ++j) {
    mesh.setNode(0, j, temperatureValue);
  }
}

void setBoundaryBottom(Mesh &mesh) {
  int choice = -1;
  int temperatureValue;
  std::cout << "Set Bottom Boundary conditions: \n"
            << "(1) Dirichlet boundary conditions \n"
            << "(2) Neumann boundary conditions \n";
  std::cout << ">> ";
  std::cin >> choice;
  std::cout << "Set temperature value T[bottom,:]: ";
  std::cin >> temperatureValue;
  for (auto j = 0u; j < mesh.numCols(); ++j) {
    mesh.setNode(mesh.numRows() - 1, j, temperatureValue);
  }
}

void setBoundaryLeft(Mesh &mesh) {
  int choice = -1;
  int temperatureValue;
  std::cout << "Set Left Boundary conditions: \n"
            << "(1) Dirichlet boundary conditions \n"
            << "(2) Neumann boundary conditions \n";
  std::cout << ">> ";
  std::cin >> choice;
  std::cout << "Set temperature value T[:,left]: ";
  std::cin >> temperatureValue;
  for (auto i = 0u; i < mesh.numRows(); ++i) {
    if (i == 0 || i == mesh.numRows() - 1) {
      mesh.setNode(i, 0, ((mesh.getNode(i, 0) + temperatureValue) / 2));
    } else {
      mesh.setNode(i, 0, temperatureValue);
    }
  }
}

void setBoundaryRight(Mesh &mesh) {
  int choice = -1;
  int temperatureValue;
  std::cout << "Set Right Boundary conditions: \n"
            << "(1) Dirichlet boundary conditions \n"
            << "(2) Neumann boundary conditions \n";
  std::cout << ">> ";
  std::cin >> choice;
  std::cout << "Set temperature value T[:,right]: ";
  std::cin >> temperatureValue;
  for (auto i = 0u; i < mesh.numRows(); ++i) {
    if (i == 0 || i == mesh.numRows() - 1) {
      mesh.setNode(
          i, mesh.numCols() - 1,
          ((mesh.getNode(i, mesh.numCols() - 1) + temperatureValue) / 2.0));
    } else {
      mesh.setNode(i, mesh.numCols() - 1, temperatureValue);
    }
  }
}

void setInnerNodes(Mesh &mesh) {
  for (auto i = 1u; i < mesh.numRows() - 1; ++i) {
    for (auto j = 1u; j < mesh.numCols() - 1; ++j) {
      // Interpolate along rows (left and right boundaries)
      double leftValue = mesh.getNode(i, 0);
      double rightValue = mesh.getNode(i, mesh.numCols() - 1);
      double rowInterpolation =
          leftValue + (rightValue - leftValue) * j / (mesh.numCols() - 1);

      // Interpolate along columns (top and bottom boundaries)
      double topValue = mesh.getNode(0, j);
      double bottomValue = mesh.getNode(mesh.numRows() - 1, j);
      double columnInterpolation =
          topValue + (bottomValue - topValue) * i / (mesh.numRows() - 1);

      // Average the two interpolated values
      double meanValue = (rowInterpolation + columnInterpolation) / 2.0;
      mesh.setNode(i, j, meanValue);
    }
  }
}

void setBoundary(Mesh &mesh) {
  setBoundaryTop(mesh);
  setBoundaryBottom(mesh);
  setBoundaryLeft(mesh);
  setBoundaryRight(mesh);
  setInnerNodes(mesh);
}