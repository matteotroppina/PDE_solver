add_subdirectory(functions)

#create executable PDEsolver
add_executable( ${PROJECT_NAME} main.cpp)

#libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Functions)