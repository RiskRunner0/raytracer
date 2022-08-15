#pragma once

#include "point3.h"
#include "vec3.h"
#include "Sphere.h"
#include "Intersection.h"
#include <vector>
#include "Translation.h"

class ray {
public:
	ray(point3 origin, vec3 direction);

	point3	Origin() const;
	vec3	Direction() const;

private:
	point3	_origin;
	vec3	_direction;
};

point3 position(ray r, float t);

std::vector<Intersection> intersect(Sphere& s, ray& r);

ray transform(ray& r, Matrix& m);