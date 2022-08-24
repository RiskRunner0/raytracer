#include "../src/vec3.h"
#include "../src/vec3.cpp"
#include "../src/point3.h"
#include "../src/point3.cpp"
#include "../src/Math.h"
#include "gtest/gtest.h"

TEST(VectorTests, SubtractingPointsCreatesVector)
{
	point3 p1{3, 2, 1};
	point3 p2{5, 6, 7};

	vec3 expected{-2, -4, -6};

	auto result = p1 - p2;
	EXPECT_EQ(typeid(result), typeid(vec3));
	EXPECT_EQ(expected, p1 - p2);
}

TEST(VectorTests, SubtractingVectorFromPointCreatesPoint)
{
	point3 p{3, 2, 1};
	vec3 v{5, 6, 7};

	point3 expected{-2, -4, -6};

	auto result = p - v;
	EXPECT_EQ(typeid(result), typeid(point3));
	EXPECT_EQ(expected, result);
}

TEST(VectorTests, Subtracting2VectorsCreatesVector)
{
	vec3 v1{3, 2, 1};
	vec3 v2{5, 6, 7};

	vec3 expected{-2, -4, -6};
	auto result = v1 - v2;

	EXPECT_EQ(typeid(result), typeid(vec3));
	EXPECT_EQ(expected, result);
}

TEST(VectorTests, SubtractingVectorFromZeroVectorNegatesVector)
{
	vec3 zero{0, 0, 0};
	vec3 v{1, -2, 3};

	vec3 expected{-1, 2, -3};
	EXPECT_EQ(expected, zero - v);
}

TEST(VectorTests, NegatingVector)
{
	vec3 a{1, -2, 3};
	vec3 expected{-1, 2, -3};

	auto result = -a;
	EXPECT_EQ(typeid(result), typeid(vec3));
	EXPECT_EQ(expected, result);
}

TEST(VectorTests, ScalarMultiplication)
{
	vec3 a{1, -2, 3};
	vec3 expected{3.5, -7, 10.5};
	vec3 result = a * 3.5;

	EXPECT_EQ(expected, result);
}

TEST(VectorTests, FractionalMultiplication)
{
	vec3 a{1, -2, 3};
	vec3 expected{0.5, -1, 1.5};
	vec3 result = a * 0.5;

	EXPECT_EQ(expected, result);
}

TEST(VectorTests, ScalarDivision)
{
	vec3 a{1, -2, 3};
	vec3 expected{0.5, -1, 1.5};
	vec3 result = a / 2;

	EXPECT_EQ(expected, result);
}

TEST(VectorTests, Magnitude)
{
	vec3 v{1, 0, 0};
	float expected = 1.0;
	float actual = v.magnitude();

	EXPECT_EQ(expected, actual);

	v = vec3{0, 1, 0};
	expected = 1.0;
	actual = v.magnitude();

	EXPECT_EQ(expected, actual);

	v = vec3{0, 0, 1};
	expected = 1.0;
	actual = v.magnitude();

	EXPECT_EQ(expected, actual);

	v = vec3{1, 2, 3};
	expected = sqrtf(14);
	actual = v.magnitude();

	EXPECT_EQ(expected, actual);

	v = vec3{-1, -2, -3};
	expected = sqrtf(14);
	actual = v.magnitude();

	EXPECT_EQ(expected, actual);
}

TEST(VectorTests, Normalize)
{
	vec3 v{4, 0, 0};
	auto expected = vec3{1, 0, 0};
	auto actual = normalize(v);

	EXPECT_TRUE(floatEqual(1.0f, actual.magnitude()));

	v = vec3{1, 2, 3};
	expected = vec3{0.26726f, 0.53452f, 0.80178f};
	actual = normalize(v);

	EXPECT_TRUE(floatEqual(1.0f, actual.magnitude()));
}

TEST(VectorTests, DotProduct)
{
	vec3 a{1, 2, 3};
	vec3 b{2, 3, 4};

	auto expected = 20.0f;
	auto actual = dot(a, b);

	EXPECT_EQ(expected, actual);
}

TEST(VectorTests, CrossProduct)
{
	vec3 a{1, 2, 3};
	vec3 b{2, 3, 4};

	vec3 expected{-1, 2, -1};
	auto actual = cross(a, b);

	EXPECT_EQ(typeid(actual), typeid(vec3));
	EXPECT_EQ(expected, actual);

	expected = vec3{1, -2, 1};
	actual = cross(b, a);

	EXPECT_EQ(typeid(actual), typeid(vec3));
	EXPECT_EQ(expected, actual);
}

TEST(VectorTests, ReflectingVectorApproachingAt45Degree)
{
	vec3 v{ 1, -1, 0 };
	vec3 n{ 0, 1, 0 };

	auto r = reflect(v, n);
	vec3 expected{ 1, 1, 0 };

	EXPECT_EQ(expected, r);
}

TEST(VectorTests, ReflectingVectorApproachingAtSlantedDegree)
{
	vec3 v{ 0, -1, 0 };
	vec3 n{ (float)sqrt(2) / 2.0f, (float)sqrt(2) / 2.0f, 0};

	auto r = reflect(v, n);
	vec3 expected{ 1, 0, 0 };

	EXPECT_EQ(expected, r);
}