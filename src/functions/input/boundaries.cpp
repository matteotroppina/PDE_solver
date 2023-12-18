#include "boundaries.h"
#include "../objects/Mesh.h"
#include "../objects/Node.h"
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <vector>

/**
 * @brief Prompts the user for a boundary value and validates the input.
 *
 * This function continuously prompts the user for a value until a valid
 * double is entered. It uses the provided prompt message during each request.
 *
 * @param prompt The message displayed to the user.
 * @return The validated double value entered by the user.
 */
double getBoundary(const std::string &prompt) {
  double inputValue;
  while (true) {
    std::cout << prompt;
    if (std::cin >> inputValue) {
      return inputValue;
    } else {
      std::cerr << "Invalid input. Please enter a valid value.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/**
 * @brief Sets the boundary temperature for a specified boundary of the mesh.
 *
 * The function sets the boundary condition (temperature) for either the top,
 * bottom, left, or right boundary of the mesh. It handles corners by averaging
 * the temperature value with adjacent values.
 *
 * @param mesh The mesh object to set the boundary on.
 * @param boundary A string representing the boundary ("Top", "Bottom", "Left",
 * "Right").
 */
void setBoundary(Mesh &mesh, const std::string &boundary) {
  double temperatureValue = getBoundary(boundary +
                                        " boundary \n"
                                        "Set temperature value T[" +
                                        boundary + "]: ");

  unsigned int start, end, fixedIndex;
  bool isHorizontal = (boundary == "Top" || boundary == "Bottom");

  start = 0;
  end = isHorizontal ? mesh.numCols() : mesh.numRows();
  fixedIndex = isHorizontal ? (boundary == "Top" ? 0 : mesh.numRows() - 1)
                            : (boundary == "Left" ? 0 : mesh.numCols() - 1);

  for (auto i = start; i < end; ++i) {
    // Determine the current row and column indices based on the orientation
    // (horizontal or vertical)
    unsigned rowIndex = isHorizontal ? fixedIndex : i;
    unsigned colIndex = isHorizontal ? i : fixedIndex;

    // Check if the current node is at a corner of the mesh
    if ((rowIndex == 0 || rowIndex == mesh.numRows() - 1) &&
        (colIndex == 0 || colIndex == mesh.numCols() - 1)) {

      double adjacentValue1, adjacentValue2;
      // Determine the first adjacent value based on the row index
      // If we are at the top row, get the value from the row below
      // If we are at the bottom row, get the value from the row above
      if (rowIndex == 0) {
        adjacentValue1 = mesh.getNode(1, colIndex); // Below
      } else {
        adjacentValue1 = mesh.getNode(mesh.numRows() - 2, colIndex); // Above
      }
      if (colIndex == 0) {
        adjacentValue2 = mesh.getNode(rowIndex, 1); // Right
      } else {
        adjacentValue2 = mesh.getNode(rowIndex, mesh.numCols() - 2); // Left
      }
      // Set the node's value to the average of the specified temperature
      // value and the two adjacent values
      mesh.setNode(rowIndex, colIndex,
                   (temperatureValue + adjacentValue1 + adjacentValue2) / 3.0);
    } else {
      // For non-corner nodes, simply set the node's value to the
      // specified temperature value
      mesh.setNode(rowIndex, colIndex, temperatureValue);
    }
  }
}

/**
 * @brief Sets the boundary temperature for a specified boundary of the mesh for
 * testing.
 *
 * The function sets the boundary condition (temperature) for either the top,
 * bottom, left, or right boundary of the mesh. It handles corners by averaging
 * the temperature value with adjacent values.
 *
 * @param mesh The mesh object to set the boundary on.
 * @param boundary A string representing the boundary ("Top", "Bottom", "Left",
 * "Right").
 * @param TemperatureValue Boundary temperature value
 */
void setBoundary(Mesh &mesh, const std::string &boundary,
                 double temperatureValue) {
  unsigned int start, end, fixedIndex;
  bool isHorizontal = (boundary == "Top" || boundary == "Bottom");

  start = 0;
  end = isHorizontal ? mesh.numCols() : mesh.numRows();
  fixedIndex = isHorizontal ? (boundary == "Top" ? 0 : mesh.numRows() - 1)
                            : (boundary == "Left" ? 0 : mesh.numCols() - 1);

  for (auto i = start; i < end; ++i) {
    // Determine the current row and column indices based on the orientation
    // (horizontal or vertical)
    unsigned rowIndex = isHorizontal ? fixedIndex : i;
    unsigned colIndex = isHorizontal ? i : fixedIndex;

    // Check if the current node is at a corner of the mesh
    if ((rowIndex == 0 || rowIndex == mesh.numRows() - 1) &&
        (colIndex == 0 || colIndex == mesh.numCols() - 1)) {

      double adjacentValue1, adjacentValue2;
      // Determine the first adjacent value based on the row index
      // If we are at the top row, get the value from the row below
      // If we are at the bottom row, get the value from the row above
      if (rowIndex == 0) {
        adjacentValue1 = mesh.getNode(1, colIndex); // Below
      } else {
        adjacentValue1 = mesh.getNode(mesh.numRows() - 2, colIndex); // Above
      }
      if (colIndex == 0) {
        adjacentValue2 = mesh.getNode(rowIndex, 1); // Right
      } else {
        adjacentValue2 = mesh.getNode(rowIndex, mesh.numCols() - 2); // Left
      }
      // Set the node's value to the average of the specified temperature
      // value and the two adjacent values
      mesh.setNode(rowIndex, colIndex,
                   (temperatureValue + adjacentValue1 + adjacentValue2) / 3.0);
    } else {
      // For non-corner nodes, simply set the node's value to the
      // specified temperature value
      mesh.setNode(rowIndex, colIndex, temperatureValue);
    }
  }
}

/**
 * @brief Sets the inner nodes of the mesh based on interpolation between
 * boundary values.
 *
 * This function interpolates values for each inner node of the mesh, based on
 * the values of its boundary nodes. It uses linear interpolation along both
 * rows and columns.
 *
 * @param mesh The mesh object whose inner nodes are to be set.
 */
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

/**
 * @brief Sets the Dirichlet boundary conditions for all four boundaries of the
 * mesh.
 *
 * This function sets Dirichlet boundary conditions (specific temperature
 * values) for the top, bottom, left, and right boundaries of the mesh. It then
 * sets the values of inner nodes based on interpolation.
 *
 * @param mesh The mesh object to set the Dirichlet boundaries on.
 */
void setDirichletBoundaries(Mesh &mesh) {
  setBoundary(mesh, "Top");
  setBoundary(mesh, "Bottom");
  setBoundary(mesh, "Left");
  setBoundary(mesh, "Right");
  setInnerNodes(mesh);
}