#include "gtest/gtest.h"
#include "../src/point3.h"
#include "../src/Matrix.h"
#include "../src/Translation.h"
#include "../src/Translation.cpp"
#define _USE_MATH_DEFINES
#include <math.h>

TEST(TranslationTests, MultiplyingByTranslationMatrix)
{
	auto transform = translation(5, -3, 2);
	point3 p{ -3, 4, 5 };
	point3 expected{ 2, 1, 7 };
	auto result = transform * p;
	EXPECT_EQ(transform * p, expected);
}

TEST(TranslationTests, MultiplyingByInverseTranslationMatrix)
{
	auto transform = translation(5, -3, 2);
	Matrix inv = *inverse(transform);
	point3 p{ -3, 4, 5 };
	point3 expected{ -8, 7, 3 };
	EXPECT_EQ(inv * p, expected);
}

TEST(TranslationTests, TranslationDoesNotAffectVectors)
{
	auto transform = translation(5, -3, 2);
	vec3 v{ -3, 4, 5 };
	point3 expected{ -8, 7, 3 };
	EXPECT_EQ(transform * v, v);
}

TEST(TranslationTests, ScalingPoints)
{
	auto transform = scaling(2, 3, 4);
	point3 p{ -4, 6, 8 };

	point3 expected{ -8, 18, 32 };
	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ScalingVectors)
{
	auto transform = scaling(2, 3, 4);
	vec3 v{ -4, 6, 8 };
	vec3 expected{ -8, 18, 32 };
	auto actual = transform * v;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, InverseOfScaling)
{
	auto transform = scaling(2, 3, 4);
	auto inv = inverse(transform);
	vec3 v{ -4, 6, 8 };

	vec3 expected{ -2, 2, 2 };
	auto actual = *inv * v;
	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, Reflection)
{
	auto transform = scaling(-1, 1, 1);
	point3 p{ 2, 3, 4 };
	point3 expected{ -2, 3, 4 };
	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, PointRotation)
{
	point3 p{ 0, 1, 0 };
	auto half_quarter = rotation_x((float)M_PI / 4.0f);
	auto full_quarter = rotation_x((float)M_PI / 2.0f);

	point3 expected{ 0.0, sqrt(2) / 2.0, sqrt(2) / 2.0 };
	auto actual = half_quarter * p;
	EXPECT_EQ(expected, actual);

	expected = point3{ 0, 0, 1 };
	actual = full_quarter * p;
	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, InversePointRotation)
{
	point3 p{ 0, 1, 0 };
	float rad = (float)M_PI / 4.0f;
	auto half_quarter = rotation_x(rad);
	auto inv = inverse(half_quarter);

	point3 expected{ 0.0, sqrt(2) / 2.0, -sqrt(2) / 2.0 };
	auto actual = *inv * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, RotateAroundYAxis)
{
	point3 p{ 0, 0, 1 };
	auto half_quarter = rotation_y((float)M_PI / 4.0f);
	auto full_quarter = rotation_y((float)M_PI / 2.0f);

	point3 expected{ sqrt(2) / 2.0f, 0.0, sqrt(2) / 2.0f };
	auto actual = half_quarter * p;

	EXPECT_EQ(expected, actual);

	expected = point3{ 1, 0, 0 };
	actual = full_quarter * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, RotateAroundZAxis)
{
	point3 p{ 0, 1, 0 };
	auto half_quarter = rotation_z((float)M_PI / 4.0f);
	auto full_quarter = rotation_z((float)M_PI / 2.0f);

	point3 expected{ -sqrt(2) / 2.0f, sqrt(2) / 2.0f, 0.0 };
	auto actual = half_quarter * p;

	EXPECT_EQ(expected, actual);

	expected = point3{ -1, 0, 0 };
	actual = full_quarter * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingXInProportionToY)
{
	auto transform = shearing(1, 0, 0, 0, 0, 0);
	point3 p{ 2, 3, 4 };
	point3 expected{ 5, 3, 4 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingXInProportionToZ)
{
	auto transform = shearing(0, 1, 0, 0, 0, 0);
	point3 p{ 2, 3, 4 };
	point3 expected{ 6, 3, 4 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingYInProportionToX)
{
	auto transform = shearing(0, 0, 1, 0, 0, 0);
	point3 p{ 2, 3, 4 };
	point3 expected{ 2, 5, 4 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingYInProportionToZ)
{
	auto transform = shearing(0, 0, 0, 1, 0, 0);
	point3 p{ 2, 3, 4 };
	point3 expected{ 2, 7, 4 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingZInProportionToX)
{
	auto transform = shearing(0, 0, 0, 0, 1, 0);
	point3 p{ 2, 3, 4 };
	point3 expected{ 2, 3, 6 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, ShearingZInProportionToY)
{
	auto transform = shearing(0, 0, 0, 0, 0, 1);
	point3 p{ 2, 3, 4 };
	point3 expected{ 2, 3, 7 };

	auto actual = transform * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, IndividualTransformationsInSequence)
{
	point3 p{ 1, 0, 1 };
	auto A = rotation_x((float)M_PI / 2);
	auto B = scaling(5, 5, 5);
	auto C = translation(10, 5, 7);

	// apply rotation
	auto p2 = A * p;
	point3 expected{ 1, -1, 0 };
	EXPECT_EQ(p2, expected);

	// apply scaling
	auto p3 = B * p2;
	expected = point3{ 5, -5, 0 };
	EXPECT_EQ(p3, expected);

	// apply transformation
	auto p4 = C * p3;
	expected = point3{ 15, 0, 7 };
	EXPECT_EQ(p4, expected);
}

TEST(TranslationTests, ChainedTransformations)
{
	point3 p{ 1, 0, 1 };
	auto A = rotation_x((float)M_PI / 2.0f);
	auto B = scaling(5, 5, 5);
	auto C = translation(10, 5, 7);

	auto T = C * B * A;
	point3 expected{ 15, 0, 7 };
	auto actual = T * p;

	EXPECT_EQ(expected, actual);
}

TEST(TranslationTests, DefaultOrientation) {
	point3 from{ 0, 0, 0 };
	point3 to{ 0, 0, -1 };
	vec3 up{ 0, 1, 0 };
	auto t = viewTransformation(from, to, up);
	EXPECT_EQ(t, IdentityMatrix4x4);
}

TEST(TranslationTests, ViewTransformationPositiveZDirection) {
	point3 from{ 0, 0, 0 };
	point3 to{ 0, 0, 1 };
	vec3 up{ 0, 1, 0 };
	auto t = viewTransformation(from, to, up);
	auto expected = scaling(-1, 1, -1);
	EXPECT_EQ(t, expected);
}

TEST(TranslationTests, ViewTransformationMovesWorld) {
	point3 from{ 0, 0, 8 };
	point3 to{ 0, 0, 0 };
	vec3 up{ 0, 1, 0 };
	auto t = viewTransformation(from, to, up);
	auto expected = translation(0, 0, -8);
	EXPECT_EQ(t, expected);
}

TEST(TranslationTests, ArbitraryTransformation) {
	point3 from{ 1, 3, 2 };
	point3 to{ 4, -2, 8 };
	vec3 up{ 1, 1, 0 };
	auto t = viewTransformation(from, to, up);

	float values[] = {
		-0.50709,	0.50709,	 0.67612,	-2.36643,
		 0.76772,	0.60609,	 0.12122,	-2.82843,
		-0.35857,	0.59761,	-0.71714,	 0.00000,
		 0.00000,	0.00000,	 0.00000,	 1.00000,
	};
	Matrix expected{ 4, 4, values };
	EXPECT_EQ(t, expected);
}