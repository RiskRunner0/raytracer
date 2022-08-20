#include "gtest/gtest.h"
#include "../src/PointLight.h"
#include "../src/PointLight.cpp"
#include "../src/Material.h"
#include "../src/Material.cpp"
#include "../src/Sphere.h"
TEST(MaterialTests, PointLightCreation)
{
	auto intensity = Color{ 1, 1, 1 };
	auto position = point3{ 0, 0, 0 };

	auto light = PointLight{ position, intensity };
	EXPECT_EQ(light.position, position);
	EXPECT_EQ(light.intensity, intensity);
}

TEST(MaterialTests, DefaultMaterial)
{
	auto m = Material{};

	Color expectedColor{ 1, 1, 1 };

	EXPECT_EQ(m.color, expectedColor);
	EXPECT_EQ(m.ambient, 0.1f);
	EXPECT_EQ(m.diffuse, 0.9f);
	EXPECT_EQ(m.specular, 0.9f);
	EXPECT_EQ(m.shininess, 200.0f);
}

TEST(MaterialTests, SphereHasDefaultMaterial)
{
	Sphere s{};

	auto m = s.material;
	Material expected{};

	EXPECT_EQ(m, expected);
}