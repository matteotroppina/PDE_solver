add_subdirectory(objects)
add_subdirectory(methods)

# Create a library "WriteToFile"
add_library(WriteToFile write_to_csv.cpp)
# Include the directory where Objects can find its header files
target_include_directories(WriteToFile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
