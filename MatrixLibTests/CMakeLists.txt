cmake_minimum_required (VERSION 3.1)

set(SRC 
 "src/vector_1d_test.cpp"
 "src/matrix_3d_test.cpp"
)

add_executable(MatrixLibTests ${SRC})
target_link_libraries(MatrixLibTests PRIVATE MatrixLib GTest::gtest GTest::gtest_main)

