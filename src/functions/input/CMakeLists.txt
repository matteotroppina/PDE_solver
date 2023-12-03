# Create a library "UserInput"
add_library(UserInput inputHandler.cpp boundaries.cpp)
# Include the directory where Objects can find its header files
target_include_directories(UserInput PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

