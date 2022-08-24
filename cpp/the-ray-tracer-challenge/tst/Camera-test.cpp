#include "gtest/gtest.h"
#include "../src/Camera.h"
#include "../src/Camera.cpp"
#include "../src/Translation.h"
#include "../src/World.h"
#include "../src/Canvas.h"
#define _USE_MATH_DEFINES
#include <math.h>

TEST(CameraTests, ConstructingACamera) {
	int hsize = 160;
	int vsize = 120;
	float fieldOfView = (float)M_PI / 2.0f;

	Camera c{ hsize, vsize, fieldOfView };

	EXPECT_EQ(c.hsize, hsize);
	EXPECT_EQ(c.vsize, vsize);
	EXPECT_EQ(c.fieldOfView, fieldOfView);
	EXPECT_EQ(*c.transformation, IdentityMatrix4x4);
}

TEST(CameraTests, PixelSizeForHorizontalCanvas) {
	Camera c{200, 125, (float)M_PI / 2.0f};

	EXPECT_EQ(floatEqual(c.pixelSize, 0.01f), true);
}

TEST(CameraTests, PixelSizeForVerticalCanvas) {
	Camera c{ 125, 200, (float)M_PI / 2.0f };

	EXPECT_EQ(floatEqual(c.pixelSize, 0.01f), true);
}

TEST(CameraTests, ConstructingRayThroughCenterOfCanvas) {
	Camera c{ 201, 101, static_cast<float>(M_PI) / 2.0f };
	auto r = rayForPixel(c, 100, 50);
	
	point3 expectedPoint{ 0, 0, 0 };
	vec3 expectedVec{ 0, 0, -1 };

	EXPECT_EQ(r.origin, expectedPoint);
	EXPECT_EQ(r.direction, expectedVec);
}

TEST(CameraTests, ConstructingRayThroughCornerOfCanvas) {
	Camera c{ 201, 101, static_cast<float>(M_PI) / 2.0f };
	auto r = rayForPixel(c, 0, 0);

	point3 expectedPoint{ 0, 0, 0 };
	vec3 expectedVec{ 0.66519f, 0.33259f, -0.66851f };

	EXPECT_EQ(r.origin, expectedPoint);
	EXPECT_EQ(r.direction, expectedVec);
}

TEST(CameraTests, ConstructingRayWithTransformedCamera) {
	Camera c{ 201, 101, static_cast<float>(M_PI) / 2.0f };
	c.transformation = new Matrix{ rotation_y(static_cast<float>(M_PI) / 4.0f) * translation(0, -2, 5)};
	auto r = rayForPixel(c, 100, 50);

	point3 expectedPoint{ 0, 2, -5 };
	vec3 expectedVec{ static_cast<float>(sqrt(2)) / 2.0f, 0, -static_cast<float>(sqrt(2)) / 2.0f };

	EXPECT_EQ(r.origin, expectedPoint);
	EXPECT_EQ(r.direction, expectedVec);
}

TEST(CameraTests, RenderAWorld) {
	World w = MakeDefaultWorld();
	Camera c{ 11, 11, static_cast<float>(M_PI) / 2.0f };
	point3 from{ 0, 0, -5 };
	point3 to{ 0, 0, 0 };
	vec3 up{ 0, 1, 0 };
	c.transformation = new Matrix{ viewTransformation(from, to, up) };

	Canvas image = render(c, w);

	Color expectedColor{ 0.38066, 0.47583, 0.2855 };
	EXPECT_EQ(image.pixelAt(5, 5), expectedColor);
}