# Create a library "IterativeMethods"
add_library(IterativeMethods jacobi.cpp gauss_seidel.cpp)
# Include the directory where Objects can find its header files
target_include_directories(IterativeMethods PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

