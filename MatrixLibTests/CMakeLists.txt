cmake_minimum_required (VERSION 3.1)

set(SRC 
 "src/matrix_1d_test.cpp"
)

add_executable(MatrixLibTests ${SRC})
target_link_libraries(MatrixLibTests PRIVATE MatrixLib GTest::gtest GTest::gtest_main)

