#include <gtest/gtest.h>
#include <matlib/vector_1d.h>


TEST(MatrixLib, Vector1D)
{
	Vector1D vec(10000, 1.5);

	// check vector contents
	EXPECT_EQ(vec.get_size(), 10000);
	for (size_t i = 0; i < vec.get_size(); i++)
	{
		EXPECT_DOUBLE_EQ(vec(i), 1.5);
	}

	// check matrix out of bound index
	EXPECT_NO_THROW(vec(9999));
	EXPECT_ANY_THROW(vec(10000));

	// check set values
	EXPECT_NO_THROW(vec.set_element(0, 3));
	EXPECT_DOUBLE_EQ(vec.get_element(0), 3);
	EXPECT_NO_THROW(vec(2) = 60);
	EXPECT_DOUBLE_EQ(vec(2), 60);

	// check resize
	EXPECT_NO_THROW(vec.resize(50));
	EXPECT_EQ(vec.get_size(), 50);

	// check elements list initializer
	EXPECT_NO_THROW(vec = Vector1D({ 1, 2, 3, 4 }));
	EXPECT_DOUBLE_EQ(vec(0), 1);
	EXPECT_DOUBLE_EQ(vec(1), 2);
	EXPECT_DOUBLE_EQ(vec(2), 3);
	EXPECT_DOUBLE_EQ(vec(3), 4);

}
