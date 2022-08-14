#pragma once

#include "tuple.h"
#include "vec3.h"

class point3 : public tuple {
public:
	point3(int x, int y, int z);
	point3(double x, double y, double z);
	point3(float x, float y, float z);
	point3(tuple t);

	point3 operator+(const vec3& rhs) const;
	point3 operator-(const vec3& rhs) const;
	vec3   operator-(const point3& rhs) const;
};