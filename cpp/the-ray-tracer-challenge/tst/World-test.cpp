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
	EXPECT_EQ(defaultWorld.spheres[0], s1);
	EXPECT_EQ(defaultWorld.spheres[1], s2);
}