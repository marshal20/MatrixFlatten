cmake_minimum_required (VERSION 3.1)

set(SRC 
 "include/matlib/matrix_1d.h"
 "src/matrix_1d.cpp"
)

add_library(MatrixLib STATIC ${SRC})

target_include_directories(MatrixLib
  PRIVATE src
  PUBLIC include
)

