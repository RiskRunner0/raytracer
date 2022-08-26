#include "../src/point3.h"
#include "../src/Matrix.h"

#include "gtest/gtest.h"
#include "../src/Matrix.cpp"
#include "../src/point3.cpp"

TEST(TransformationTests, Translation)
{
	auto transform = translation( 5, -3, 2 );
	point3 p{ -3, 4, 5 };

	point3 expected{ 2, 1, 7 };

	auto result = transform * p;

	EXPECT_EQ(expected, *result);
}

TEST(TransformationTests, MultiplyingOfInverse)
{
	auto transform = translation(5, -3, 2);

	auto inv = inverse(transform);

	auto p = point3{ -3, 4, 5 };

	auto expected = point3{ -8, 7, 3 };

	auto result = (*inv) * p;

	EXPECT_EQ(expected, *result);
}

TEST(TransformationTests, MultiplyingByVectorDoesntChangeVector)
{
	auto transform = translation(5, -3, 2);

	auto v = vec3{ -3, 4, 5 };

	auto expected = v;

	auto result = transform * v;

	EXPECT_EQ(expected, *result);
}