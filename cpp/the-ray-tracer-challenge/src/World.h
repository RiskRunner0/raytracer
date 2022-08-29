#pragma once

#include "PointLight.h"
#include "Sphere.h"
#include "Intersection.h"
#include <vector>
#include "Translation.h"
#include <algorithm>
#include "vec3.h"

class World {
public:
	World(PointLight light, std::vector<Shape*> spheres);

	PointLight light;
	std::vector<Shape*> spheres;
};

struct PreparedComputations {
	float   t;
	Shape* object;
	point3  point;
	point3  overPoint;
	vec3    eyeV;
	vec3    normalV;
	bool	inside = false;
};

World MakeDefaultWorld();

std::vector<Intersection> intersectWorld(const World& w, const ray& r);

PreparedComputations prepareComputations(Intersection& i, ray& r);

Color shadeHit(World world, PreparedComputations comps);

Color colorAt(World& world, ray& r);

bool isShadowed(World world, point3 point);