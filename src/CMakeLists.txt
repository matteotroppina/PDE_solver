add_subdirectory(functions)

#create executable PDEsolver
add_executable( ${PROJECT_NAME} main.cpp)

#libraries
target_link_libraries(${PROJECT_NAME} PRIVATE WriteToFile)
target_link_libraries(${PROJECT_NAME} PRIVATE Objects)
target_link_libraries(${PROJECT_NAME} PRIVATE UserInput)
target_link_libraries(${PROJECT_NAME} PRIVATE IterativeMethods)
target_link_libraries(${PROJECT_NAME} PRIVATE Tests)