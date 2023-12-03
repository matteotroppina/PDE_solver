# Create a library "Objects"
add_library(Functions Mesh.cpp boundaries.cpp jacobi.cpp gauss_seidel.cpp write_to_csv.cpp)

# Include the directory where Objects can find its header files
target_include_directories(Functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
