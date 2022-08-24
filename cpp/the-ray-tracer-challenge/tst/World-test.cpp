#include "gtest/gtest.h"

#include "../src/PointLight.h"
#include "../src/Sphere.h"
#include "../src/Translation.h"
#include "../src/World.h"
#include "../src/World.cpp"

TEST(WorldTests, DefaultWorld) {
	PointLight light{ point3{-10, 10, -10}, Color{1.0, 1.0, 1.0} };
	
	Sphere s1{};
	Material m{};
	m.color = Color{ 0.8, 1.0, 0.6 };
	m.diffuse = 0.7f;
	m.specular = 0.2f;
	s1.material = m;

	Sphere s2{};
	s2.transformation = new Matrix{ scaling(0.5, 0.5, 0.5) };

	World defaultWorld = MakeDefaultWorld();

	EXPECT_EQ(defaultWorld.light, light);
	EXPECT_EQ(*defaultWorld.spheres[0], s1);
	EXPECT_EQ(*defaultWorld.spheres[1], s2);
}

TEST(WorldTests, IntersectAWorldWithARay) {
	World w = MakeDefaultWorld();
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };

	auto xs = intersectWorld(w, r);

	EXPECT_EQ(xs.size(), 4);
	EXPECT_EQ(xs[0].t, 4);
	EXPECT_EQ(xs[1].t, 4.5);
	EXPECT_EQ(xs[2].t, 5.5);
	EXPECT_EQ(xs[3].t, 6);
}

TEST(WorldTests, PrecomputingIntersection) {
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };
	Sphere shape{ };

	Intersection i{ 4, &shape };

	auto comps = prepareComputations(i, r);
	EXPECT_EQ(comps.t, i.t);
	EXPECT_EQ(comps.object, i.object);
	point3 expectedPoint{ 0, 0, -1 };
	EXPECT_EQ(comps.point, expectedPoint);
	vec3 expectedEyeV{ 0, 0, -1 };
	EXPECT_EQ(comps.eyeV, expectedEyeV);
	vec3 expectedNormalV{ 0, 0, -1 };
	EXPECT_EQ(comps.normalV, expectedNormalV);
}

TEST(WorldTests, HitWhenIntersectionOccursInside) {
	ray r{ point3{0, 0, 0 }, vec3{0, 0, 1 } };
	Sphere shape{};
	Intersection i{ 1, &shape };

	auto comps = prepareComputations(i, r);

	point3 expectedPoint{ 0, 0, 1 };
	EXPECT_EQ(comps.point, expectedPoint);
	vec3 expectedEyeV{ 0, 0, -1 };
	EXPECT_EQ(comps.eyeV, expectedEyeV);
	vec3 expectedNormalV{ 0, 0, -1 };
	EXPECT_EQ(comps.normalV, expectedNormalV);
	EXPECT_EQ(comps.inside, true);
}

TEST(WorldTests, ShadingAnIntersection) {
	auto w = MakeDefaultWorld();
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };
	Sphere* shape = w.spheres[0];
	Intersection i{ 4, shape };

	auto comps = prepareComputations(i, r);
	auto c = shadeHit(w, comps);
	
	Color expectedColor{ 0.38066, 0.47583, 0.2855 };
	EXPECT_EQ(c, expectedColor);
}

TEST(WorldTests, ShadingAnIntersectionFromInside) {
	auto w = MakeDefaultWorld();
	w.light = PointLight{ point3{0.0, 0.25, 0.0}, Color{1, 1, 1} };
	ray r{ point3{0, 0, 0}, vec3{0, 0, 1} };
	Sphere* shape = w.spheres[1];
	Intersection i{ 0.5, shape };

	auto comps = prepareComputations(i, r);
	auto c = shadeHit(w, comps);

	Color expectedColor{ 0.90498, 0.90498, 0.90498 };
	EXPECT_EQ(c, expectedColor);
}

TEST(WorldTests, ColorWhenRayMisses) {
	auto w = MakeDefaultWorld();
	ray r{ point3{0, 0, -5}, vec3{0, 1, 0} };
	auto c = colorAt(w, r);

	Color expectedColor{ 0, 0, 0 };
	EXPECT_EQ(c, expectedColor);
}

TEST(WorldTests, ColorWhenRayHits) {
	auto w = MakeDefaultWorld();
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };
	auto c = colorAt(w, r);

	Color expectedColor{ 0.38066, 0.47583, 0.2855 };
	EXPECT_EQ(c, expectedColor);
}

TEST(WorldTests, ColorIntersectionBehindRay) {
	auto w = MakeDefaultWorld();
	Sphere* outer = w.spheres[0];
	outer->material.ambient = 1;
	Sphere* inner = w.spheres[1];
	inner->material.ambient = 1;

	ray r{ point3{0.0, 0.0, 0.75}, vec3{0, 0, -1} };
	auto c = colorAt(w, r);

	Color expectedColor(inner->material.color);
	EXPECT_EQ(c, expectedColor);
}