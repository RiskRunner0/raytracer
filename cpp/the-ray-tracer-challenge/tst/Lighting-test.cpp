#include "gtest/gtest.h"
#include "../src/vec3.h"
#include "../src/PointLight.h"
#include "../src/Color.h"
#include "../src/Material.h"
#include "../src/World.h"

TEST(LightingTests, EyeBetweenLightAndSurface)
{
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyev{ 0, 0, -1 };
	vec3 normalv{ 0, 0, -1 };
	PointLight light{ point3{0, 0, -10}, Color{1, 1, 1} };
	auto result = lighting(m, light, position, eyev, normalv, false);
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
	auto result = lighting(m, light, position, eyev, normalv, false);
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
	auto result = lighting(m, light, position, eyev, normalv, false);
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
	auto result = lighting(m, light, position, eyev, normalv, false);
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
	auto result = lighting(m, light, position, eyev, normalv, false);
	Color expected{ 0.1, 0.1, 0.1 };

	EXPECT_EQ(result, expected);
}

TEST(LightingTests, LightingWithTheSurfaceInShadow) {
	Material m{};
	point3 position{ 0, 0, 0 };
	vec3 eyeV{ 0, 0, -1 };
	vec3 normalV{ 0, 0, -1 };
	PointLight light{ point3{0, 0, -10}, Color{1, 1, 1} };
	bool inShadow = true;

	auto result = lighting(m, light, position, eyeV, normalV, inShadow);
	Color expected{ 0.1, 0.1, 0.1 };
	EXPECT_EQ(result, expected);
}

TEST(LightingTests, NoShadowWhenNothingIsCollinear) {
	World w = MakeDefaultWorld();
	point3 p{ 0, 10, 0 };
	auto shadowed = isShadowed(w, p);
	EXPECT_FALSE(shadowed);
}

TEST(LightingTests, ShadowWhenObjectIsBetweenPointAndLight) {
	World w = MakeDefaultWorld();
	point3 p{ 10, -10, 10 };
	auto shadowed = isShadowed(w, p);

	EXPECT_TRUE(shadowed);
}

TEST(LightingTests, NoShadowBehindLight) {
	World w = MakeDefaultWorld();
	point3 p{ -20, 20,-20 };
	auto shadowed = isShadowed(w, p);

	EXPECT_FALSE(shadowed);
}

TEST(LightingTests, NoShadowBetweenLightAndPoint) {
	World w = MakeDefaultWorld();
	point3 p{ -2, 2,-2 };
	auto shadowed = isShadowed(w, p);

	EXPECT_FALSE(shadowed);
}

TEST(LightingTests, ShadeHitGivenAnIntersectionToShadow) {
	World w = MakeDefaultWorld();
	w.light = PointLight{ point3{0, 0, -10}, Color{1, 1, 1} };

	Sphere s1{};
	w.spheres.push_back(&s1);

	Sphere s2{};
	s2.transformation = new Matrix(translation(0, 0, 10));

	w.spheres.push_back(&s2);

	ray r{ point3{0, 0, 5}, vec3{0, 0, 1} };
	Intersection i{ 4, &s2 };
	
	auto comps = prepareComputations(i, r);
	auto c = shadeHit(w, comps);

	Color expectedColor{ 0.1, 0.1, 0.1 };

	EXPECT_EQ(c, expectedColor);
}

TEST(LightingTests, HitShouldOffsetPoint) {
	ray r{ point3{0, 0, -5}, vec3{0, 0, -1} };
	Sphere shape{};
	shape.transformation = new Matrix(translation(0, 0, 1));

	Intersection i{ 5, &shape };

	auto comps = prepareComputations(i, r);

	EXPECT_TRUE(comps.overPoint.z() < (- (float)EPSILON / 2.0f));
	EXPECT_TRUE(comps.point.z() > comps.overPoint.z());
}