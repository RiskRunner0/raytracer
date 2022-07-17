#include "gtest/gtest.h"

#include "../src/tuple.h"
#include "../src/tuple.cpp"

TEST(TupleTests, MultiplyByScalar) {
	auto a = tuple{ 1, -2, 3, -4 };

	auto expected = tuple{ 3.5, -7, 10.5, -14 };

	auto result = a * 3.5;

	EXPECT_EQ(typeid(result), typeid(tuple));
	EXPECT_EQ(expected, result);
}

TEST(TupleTests, DivideByScalar) {
	tuple a{ 1, -2, 3, -4 };

	tuple expected{ 0.5, -1, 1.5, -2 };

	auto result = a / 2;

	EXPECT_EQ(typeid(result), typeid(tuple));
	EXPECT_EQ(expected, result);
}