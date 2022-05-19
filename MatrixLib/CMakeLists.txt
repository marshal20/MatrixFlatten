cmake_minimum_required (VERSION 3.1)

set(SRC 
 "include/matlib/vector_1d.h"
 "src/vector_1d.cpp"
 "include/matlib/matrix_3d.h"
 "src/matrix_3d.cpp"
)

add_library(MatrixLib STATIC ${SRC})

target_include_directories(MatrixLib
  PRIVATE src
  PUBLIC include
)

