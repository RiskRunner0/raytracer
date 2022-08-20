#include "gtest/gtest.h"
#include "../src/Sphere.h"
#include "../src/vec3.h"
#include "../src/Translation.h"
#define _USE_MATH_DEFINES
#include <math.h>

TEST(SphereTests, NormalAtPointOnXAxis)
{
	Sphere s{};
	auto n = normalAt(s, point3{ 1, 0, 0 });
	vec3 expected{ 1, 0, 0 };
	EXPECT_EQ(expected, n);
}

TEST(SphereTests, NormalAtPointOnYAxis)
{
	Sphere s{};
	auto n = normalAt(s, point3{ 0, 1, 0 });
	vec3 expected{ 0, 1, 0 };
	EXPECT_EQ(expected, n);
}

TEST(SphereTests, NormalAtPointOnZAxis)
{
	Sphere s{};
	auto n = normalAt(s, point3{ 0, 0, 1 });
	vec3 expected{ 0, 0, 1 };
	EXPECT_EQ(expected, n);
}

TEST(SphereTests, NormalAtNonaxialPoint)
{
	Sphere s{};
	float sqrtOf3 = (float)sqrt(3);
	auto n = normalAt(s, point3{ sqrtOf3 / 3.0f, sqrtOf3 / 3.0f, sqrtOf3 / 3.0f });
	vec3 expected{ sqrtOf3 / 3.0f, sqrtOf3 / 3.0f, sqrtOf3 / 3.0f };
	EXPECT_EQ(expected, n);
}

TEST(SphereTests, NormalVectorIsNormalized)
{
	Sphere s{};
	float sqrtOf3 = (float)sqrt(3);
	auto n = normalAt(s, point3{ sqrtOf3 / 3.0f, sqrtOf3 / 3.0f, sqrtOf3 / 3.0f });
	EXPECT_EQ(n, normalize(n));
}

TEST(SphereTests, ComputingNormalOnTranslatedSphere)
{
	Sphere s{};
	s.SetTransformation(translation(0, 1, 0));

	auto n = normalAt(s, point3{ 0.0f, 1.70711f, -0.70711f });
	auto expected = vec3{ 0.0f, 0.70711f, -0.70711f };

	EXPECT_EQ(expected, n);
}

TEST(SphereTests, ComputingNormalOnTransformedSphere)
{
	Sphere s{};
	auto m = scaling(1, 0.5, 1) * rotation_z((float)M_PI / 5);
	s.SetTransformation(m);

	auto n = normalAt(s, point3{ 0.0f, (float)sqrt(2) / 2.0f, -(float)sqrt(2) / 2.0f });
	auto expected = vec3{ 0.0, 0.97014, -0.24254 };

	EXPECT_EQ(expected, n);
}