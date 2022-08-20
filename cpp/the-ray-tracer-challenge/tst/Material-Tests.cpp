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
	EXPECT_EQ(light.Position(), position);
	EXPECT_EQ(light.Intensity(), intensity);
}

TEST(MaterialTests, DefaultMaterial)
{
	auto m = Material{};

	Color expectedColor{ 1, 1, 1 };

	EXPECT_EQ(m.GetColor(), expectedColor);
	EXPECT_EQ(m.Ambient(), 0.1f);
	EXPECT_EQ(m.Diffuse(), 0.9f);
	EXPECT_EQ(m.Specular(), 0.9f);
	EXPECT_EQ(m.Shininess(), 200.0f);
}

TEST(MaterialTests, SphereHasDefaultMaterial)
{
	Sphere s{};

	auto m = s.GetMaterial();
	Material expected{};

	EXPECT_EQ(m, expected);
}