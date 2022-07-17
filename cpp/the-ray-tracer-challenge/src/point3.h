#pragma once

#include "tuple.h"
#include "vec3.h"

class point3 : public tuple {
public:
	point3(float x, float y, float z);
	point3(tuple t);
};

point3::point3(float x, float y, float z) : tuple(x, y, z, 1.0) {};

point3::point3(tuple t) : point3::point3(t.x(), t.y(), t.z()) {};

inline
point3 operator+(const point3& lhs, const vec3& rhs) {
	return point3{ (tuple)lhs + (tuple)rhs };
}

inline
point3 operator-(const point3& lhs, const vec3& rhs) {
	return point3{ (tuple)lhs - (tuple)rhs };
}

inline
vec3 operator-(const point3& lhs, const point3& rhs) {
	return point3{ (tuple)lhs - (tuple)rhs };
}