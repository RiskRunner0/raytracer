#include "gtest/gtest.h"
#include "../src/vec3.h"
#include "../src/PointLight.h"
#include "../src/Color.h"
#include "../src/Material.h"

TEST(LightingTests, EyeBetweenLightAndSurface)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0, 0, -1 };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 0, -10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv);
	Color expected{ 1.9, 1.9, 1.9 };

	EXPECT_EQ(result, expected);
}

TEST(LightingTests, EyeOffset45Degrees)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0, (float)sqrt(2) / 2.0f, -(float)sqrt(2) / 2.0f };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 0, -10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv);
	Color expected{ 1.0, 1.0, 1.0 };

	EXPECT_EQ(result, expected);
}

TEST(LightingTests, LightOffset45Degrees)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0, 0, -1 };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 10, -10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv);
	Color expected{ 0.7364, 0.7364, 0.7364 };

	EXPECT_EQ(result, expected);
}

TEST(LightingTests, EyeInReflectivePath)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0,-(float)sqrt(2) / 2.0f, -(float)sqrt(2) / 2.0f };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 10, -10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv);
	Color expected{ 1.63639, 1.63639, 1.63639 };

	EXPECT_EQ(result, expected);
}

TEST(LightingTests, LightBehindSurface)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0, 0, -1 };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 0, 10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv);
	Color expected{ 0.1, 0.1, 0.1 };

	EXPECT_EQ(result, expected);
}