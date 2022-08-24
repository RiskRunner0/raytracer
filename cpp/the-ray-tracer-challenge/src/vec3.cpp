#include "vec3.h"

vec3::vec3() : vec3(0.0f, 0.0f, 0.0f) {}

vec3::vec3(float x, float y, float z) : tuple(x, y, z, 0.0f) {
	_magnitude = sqrt(vec3::x() * vec3::x() + vec3::y() * vec3::y() + vec3::z() * vec3::z());
}

vec3::vec3(tuple t) : vec3(t.x(), t.y(), t.z()) {
}

float vec3::magnitude() const { return _magnitude; }

vec3 vec3::operator+(const vec3& rhs) const {
	return vec3{
		(tuple)(*this)+tuple(rhs)
	};
}

vec3 vec3::operator-(const vec3& rhs) const {
	return vec3{ (tuple)(*this) - (tuple)rhs};
}

vec3 vec3::operator-() const {
	return vec3{ -(tuple)(*this)};
}

float dot(const vec3& a, const vec3& b)
{
	return	(a.x() * b.x()) +
		(a.y() * b.y()) +
		(a.z() * b.z());
}

vec3 cross(const vec3& a, const vec3& b) {
	return vec3{ a.y() * b.z() - a.z() * b.y(),
				 a.z() * b.x() - a.x() * b.z(),
				 a.x() * b.y() - a.y() * b.x()
	};
}

vec3 normalize(const vec3& v) {
	return vec3{
		v.x() / v.magnitude(),
		v.y() / v.magnitude(),
		v.z() / v.magnitude()
	};
}

vec3 reflect(const vec3& v, const vec3& normal) {
	return v - normal * 2 * dot(v, normal);
}