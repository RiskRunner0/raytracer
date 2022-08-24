#include "gtest/gtest.h"

#include "../src/point3.h"
#include "../src/Ray.h"
#include "../src/Ray.cpp"
#include "../src/Sphere.h"
#include "../src/Sphere.cpp"
#include "../src/Intersection.h"
#include "../src/Intersection.cpp"
#include "../src/Translation.h"

TEST(RayTests, CreateAndQueryRay)
{
	point3 origin{ 1, 2, 3 };
	vec3 direction{ 4, 5, 6 };

	ray r{ origin, direction };
	EXPECT_EQ(r.origin, origin);
	EXPECT_EQ(r.direction, direction);
}

TEST(RayTests, PointFromDistance)
{
	point3 origin{ 2, 3, 4 };
	vec3 dir{ 1, 0, 0 };
	ray r{ origin, dir };

	point3 expected{ 2, 3, 4 };
	EXPECT_EQ(position(r, 0), expected);

	expected = point3{ 3, 3, 4 };
	EXPECT_EQ(position(r, 1), expected);

	expected = point3{ 1, 3, 4 };
	EXPECT_EQ(position(r, -1), expected);

	expected = point3{ 4.5, 3.0, 4.0 };
	EXPECT_EQ(position(r, 2.5), expected);
}

TEST(RayTests, IntersectsSphereAt2Points)
{
	point3 origin{ 0, 0, -5 };
	vec3 dir{ 0, 0, 1 };

	ray r{ origin, dir };
	Sphere s{};

	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].t, 4.0);
	EXPECT_EQ(xs[1].t, 6.0);
}

TEST(RayTests, IntersectsAtTangent)
{
	ray r{ point3{0, 1, -5}, vec3{0, 0, 1} };
	Sphere s{};
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].t, 5.0);
	EXPECT_EQ(xs[1].t, 5.0);
}

TEST(RayTests, DoesntIntersect)
{
	ray r{ point3{0, 2, -5}, vec3{0, 0, 1} };
	Sphere s{};
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 0);
}

TEST(RayTests, RayStartsInMiddleOfCircle)
{
	ray r{ point3{0, 0, 0}, vec3{0, 0, 1} };
	Sphere s{};
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].t, -1.0);
	EXPECT_EQ(xs[1].t, 1.0);
}

TEST(RayTests, RayInFrontofCircle)
{
	ray r{ point3{0, 0, 5}, vec3{0, 0, 1} };
	Sphere s{};
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].t, -6.0);
	EXPECT_EQ(xs[1].t, -4.0);
}

TEST(RayTests, IntersectionEncapsulation)
{
	Sphere s{};
	Intersection i{ 3.5, &s };

	EXPECT_EQ(i.t, 3.5);
	EXPECT_EQ(i.object, &s);
}

TEST(RayTests, IntersectSetsObjectOnIntersection)
{
	ray r{ point3{0, 0, 5}, vec3{0, 0, 1} };
	Sphere s{};
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].object, &s);
	EXPECT_EQ(xs[1].object, &s);
}

TEST(RayTests, AllIntersectionsPositiveT)
{
	Sphere s{};
	Intersection i1{ 1, &s };
	Intersection i2{ 2, &s };
	std::vector<Intersection> xs = intersections(std::vector<Intersection>{ i2, i1 });
	auto i = hit(xs);

	EXPECT_EQ(*i, i1);
}

TEST(RayTests, SomeIntersectionsNegativeT)
{
	Sphere s{};
	Intersection i1{ -1, &s };
	Intersection i2{ 1, &s };
	std::vector<Intersection> xs = intersections(std::vector<Intersection>{ i2, i1 });
	auto i = hit(xs);

	EXPECT_EQ(*i, i2);
}

TEST(RayTests, AllIntersectionsNegativeT)
{
	Sphere s{};
	Intersection i1{ -2, &s };
	Intersection i2{ -1, &s };
	std::vector<Intersection> xs = intersections(std::vector<Intersection>{ i2, i1 });
	auto i = hit(xs);

	EXPECT_EQ(i, nullptr);
}

TEST(RayTests, HitAlwaysLowestNonNegativeNumber)
{
	Sphere s{};
	Intersection i1{ 5, &s };
	Intersection i2{ 7, &s };
	Intersection i3{ -3, &s };
	Intersection i4{ 2, &s };
	std::vector<Intersection> xs = intersections(std::vector<Intersection>{ i1, i2, i3, i4 });
	auto i = hit(xs);

	EXPECT_EQ(*i, i4);
}

TEST(RayTests, TranslatingRay)
{
	ray r{ point3{1, 2, 3}, vec3{0, 1, 0} };
	auto m = translation(3, 4, 5);
	auto r2 = transform(r, m);
	
	point3 expectedPt{ 4, 6, 8 };
	EXPECT_EQ(r2.origin, expectedPt);

	vec3 expectedVec{ 0, 1, 0 };
	EXPECT_EQ(r2.direction, expectedVec);
}

TEST(RayTests, ScalingRay)
{
	ray r{ point3{1, 2, 3}, vec3{0, 1, 0} };
	auto m = scaling(2, 3, 4);
	auto r2 = transform(r, m);

	point3 expectedPt{ 2, 6, 12 };
	EXPECT_EQ(r2.origin, expectedPt);

	vec3 expectedVec{ 0, 3, 0 };
	EXPECT_EQ(r2.direction, expectedVec);
}

TEST(RayTests, SphereTransformation)
{
	Sphere s{};
	EXPECT_EQ(*s.transformation, IdentityMatrix4x4);
}

TEST(RayTests, ChangeSphereTransformation)
{
	Sphere s{};
	auto t = translation(2, 3, 4);
	s.transformation = new Matrix{ t };
	EXPECT_EQ(*s.transformation, t);
}

TEST(RayTests, IntersectingScaledSphereWithRay)
{
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };
	Sphere s{};
	s.transformation = new Matrix{ scaling(2, 2, 2) };
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 2);
	EXPECT_EQ(xs[0].t, 3);
	EXPECT_EQ(xs[1].t, 7);
}

TEST(RayTests, IntersectingTranslatedSphereWithRay)
{
	ray r{ point3{0, 0, -5}, vec3{0, 0, 1} };
	Sphere s{};
	s.transformation = new Matrix{ translation(5, 0, 0) };
	auto xs = intersect(&s, r);

	EXPECT_EQ(xs.size(), 0);
}