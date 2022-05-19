#include <gtest/gtest.h>
#include <matlib/matrix_1d.h>


TEST(MatrixLib, Matrix1D)
{
	Matrix1D mat(10000, 1.5);

	// check matrix contents
	EXPECT_EQ(mat.get_size(), 10000);
	for (size_t i = 0; i < mat.get_size(); i++)
	{
		EXPECT_DOUBLE_EQ(mat(i), 1.5);
	}

	// check matrix out of bound index
	EXPECT_NO_THROW(mat(9999));
	EXPECT_ANY_THROW(mat(10000));

	// check set values
	EXPECT_NO_THROW(mat.set_element(0, 3));
	EXPECT_DOUBLE_EQ(mat.get_element(0), 3);
	EXPECT_NO_THROW(mat(2) = 60);
	EXPECT_DOUBLE_EQ(mat(2), 60);

	// check resize
	EXPECT_NO_THROW(mat.resize(50));
	EXPECT_EQ(mat.get_size(), 50);

	// check elements list initializer
	EXPECT_NO_THROW(mat = Matrix1D({ 1, 2, 3, 4 }));
	EXPECT_DOUBLE_EQ(mat(0), 1);
	EXPECT_DOUBLE_EQ(mat(1), 2);
	EXPECT_DOUBLE_EQ(mat(2), 3);
	EXPECT_DOUBLE_EQ(mat(3), 4);

}
