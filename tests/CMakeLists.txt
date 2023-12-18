add_library(Tests jacobiTest.cpp)
# Include the directory where Objects can find its header files
target_include_directories(Tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})