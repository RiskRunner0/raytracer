#pragma once

#include "point3.h"
#include "Object.h"
#include "Matrix.h"
#include "vec3.h"
#include "Material.h"
#include "Math.h"

class Sphere : public Object {
public:
	Sphere();

	float    radius;
	point3   center;
	Matrix*  transformation;
	Material material;
};

vec3 normalAt(Sphere s, point3 p);

inline
bool operator==(const Sphere& lhs, const Sphere& rhs) {
	return floatEqual(lhs.radius, rhs.radius) &&
		lhs.center == rhs.center &&
		*lhs.transformation == *rhs.transformation &&
		lhs.material == rhs.material;
}