#pragma once

#include "PointLight.h"
#include "Sphere.h"
#include "Intersection.h"
#include <vector>
#include "Translation.h"
#include <algorithm>

class World {
public:
	World(PointLight light, std::vector<Sphere*> spheres);

	PointLight light;
	std::vector<Sphere*> spheres;
};

struct PreparedComputations {
	float   t;
	Sphere* object;
	point3  point;
	vec3    eyeV;
	vec3    normalV;
	bool	inside = false;
};

World MakeDefaultWorld();

std::vector<Intersection> intersectWorld(const World& w, const ray& r);

PreparedComputations prepareComputations(Intersection& i, ray& r);

Color shadeHit(World world, PreparedComputations comps);

Color colorAt(World& world, ray& r);