# Create a library "Objects"
add_library(Objects Mesh.cpp)
# Include the directory where Objects can find its header files
target_include_directories(Objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})