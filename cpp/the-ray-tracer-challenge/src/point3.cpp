#include "point3.h"

point3::point3(float x, float y, float z) : tuple(x, y, z, 1.0) {};

point3::point3(int x, int y, int z) : point3((float)x, (float)y, (float(z))) {};

point3::point3(double x, double y, double z) : point3((float)x, (float)y, (float(z))) {};

point3::point3(tuple t) : point3::point3(t.x(), t.y(), t.z()) {};

point3 point3::operator+(const vec3& rhs) const {
	return point3{ (tuple)(*this) + (tuple)rhs};
}

inline
point3 point3::operator-(const vec3& rhs) const {
	return point3{ (tuple)(*this) - (tuple)rhs };
}

inline
vec3 point3::operator-(const point3& rhs) const {
	return point3{ (tuple)(*this) - (tuple)rhs};
}