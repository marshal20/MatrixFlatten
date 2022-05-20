cmake_minimum_required(VERSION 3.1)
project(MatrixLib)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

# dependencies
# Google Test Library
set(gtest_force_shared_crt ON CACHE BOOL "gtest_force_shared_crt" FORCE)
add_subdirectory("External/googletest")

# projects
add_subdirectory(MatrixLib)
add_subdirectory(MatrixLibTests)
