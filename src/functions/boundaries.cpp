#include "Mesh.h"
#include "Node.h"
#include <iostream>
#include <memory>
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
  for (auto j = 0u; j < mesh.getCols() - 1; j++) {
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
  for (auto j = 0u; j < mesh.getCols() - 1; j++) {
    mesh.setNode(mesh.getRows() - 1, j, temperatureValue);
  }
}

void setBoundaryLeft(Mesh &mesh) {
  int choice = -1;
  int temperatureValue;
  std::cout << "Set Right Boundary conditions: \n"
            << "(1) Dirichlet boundary conditions \n"
            << "(2) Neumann boundary conditions \n";
  std::cout << ">> ";
  std::cin >> choice;
  std::cout << "Set temperature value T[:,left]: ";
  std::cin >> temperatureValue;
  for (auto i = 0u; i < mesh.getRows() - 1; i++) {
    mesh.setNode(i, 0, temperatureValue);
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
  for (auto i = 0u; i < mesh.getRows() - 1; i++) {
    mesh.setNode(i, mesh.getCols() - 1, temperatureValue);
  }
}

void setBoundary(Mesh &mesh) {
  setBoundaryTop(mesh);
  setBoundaryBottom(mesh);
  setBoundaryLeft(mesh);
  setBoundaryRight(mesh);
}