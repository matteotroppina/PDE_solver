add_subdirectory(objects)

#create executable PDEsolver
add_executable( ${PROJECT_NAME} main.cpp)

#libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Objects)