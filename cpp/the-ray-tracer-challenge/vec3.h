#pragma once

#ifndef VEC_H
#define VEC_H

#include "Math.h"

class vec3 {
public:
	vec3(float x, float y, float z): _e{x, y, z}
	{
		_magnitude = sqrt(x * x + y * y + z * z);
	}

	float x() const { return _e[0]; }
	float y() const { return _e[1]; }
	float z() const { return _e[2]; }
	float magnitude() const { return _magnitude; }

	vec3 normalize() const {
		return vec3{
			x() / _magnitude,
			y() / _magnitude,
			z() / _magnitude
		};
	}

private:
	float _e[3];
	float _magnitude;
};

using point3 = vec3;

inline vec3 operator+(const vec3& a, const vec3& b) {
	return vec3{ a.x() + b.x(), a.y() + b.y(), a.z() + b.z() };
}

inline bool operator==(const vec3& lhs, const vec3& rhs) {
	return floatEqual(lhs.x(), rhs.x()) && floatEqual(lhs.y(), rhs.y()) && floatEqual(lhs.z(), rhs.z());
}

inline vec3 operator-(const vec3& a, const vec3& b) {
	return vec3{ a.x() - b.x(), a.y() - b.y(), a.z() - b.z() };
}

inline vec3 operator-(const vec3& a)
{
	return vec3{ -a.x(), -a.y(), -a.z() };
}

inline vec3 operator*(const vec3& lhs, float rhs) {
	return vec3{ lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs };
}

inline vec3 operator/(const vec3& lhs, float rhs) {
	return vec3{ lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs };
}

inline float dot(const vec3& a, const vec3& b)
{
	return	a.x() * b.x() +
			a.y() * b.y() +
			a.z() * b.z();
}

inline vec3 cross(const vec3& a, const vec3& b)
{
	return vec3{ a.y() * b.z() - a.z() * b.y(),
				 a.z() * b.x() - a.x() * b.z(),
				 a.x() * b.y() - a.y() * b.x() };
}

#endif