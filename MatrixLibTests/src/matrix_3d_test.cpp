#include <gtest/gtest.h>
#include <matlib/matrix_3d.h>


TEST(MatrixLib, Matrix3D)
{
	Matrix3D mat({5, 5, 5}, 1.5);

	// check vector contents
	EXPECT_EQ(mat.get_size().rows, 5);
	EXPECT_EQ(mat.get_size().columns, 5);
	EXPECT_EQ(mat.get_size().pages, 5);
	for (size_t k = 0; k < mat.get_size().pages; k++)
	{
		for (size_t j = 0; j < mat.get_size().columns; j++)
		{
			for (size_t i = 0; i < mat.get_size().rows; i++)
			{
				EXPECT_DOUBLE_EQ(mat(i, j, k), 1.5);
			}
		}
	}

	// check matrix out of bound index
	EXPECT_NO_THROW(mat(4, 4, 4));
	EXPECT_ANY_THROW(mat(4, 4, 5));

	// check set values
	EXPECT_NO_THROW(mat.set_element(0, 0, 0, 3));
	EXPECT_DOUBLE_EQ(mat.get_element(0, 0, 0), 3);
	EXPECT_NO_THROW(mat(1, 2, 4) = 60);
	EXPECT_DOUBLE_EQ(mat(1, 2, 4), 60);

	// check resize
	EXPECT_NO_THROW(mat.resize({ 8, 9, 10 }));
	EXPECT_EQ(mat.get_size().rows, 8);
	EXPECT_EQ(mat.get_size().columns, 9);
	EXPECT_EQ(mat.get_size().pages, 10);

}
