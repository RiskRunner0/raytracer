#pragma once

#include "PointLight.h"
#include "Sphere.h"
#include <vector>

class World {
public:
	World(PointLight light, std::vector<Sphere> spheres);

	PointLight light;
	std::vector<Sphere> spheres;
};

World MakeDefaultWorld();