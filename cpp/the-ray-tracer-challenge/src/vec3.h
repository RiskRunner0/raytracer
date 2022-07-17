#pragma once

#include "Math.h"
#include "tuple.h"

#include <iostream>

class vec3 : public tuple {
public:
	vec3(float x, float y, float z);

	vec3(tuple t);

	float magnitude() const { return _magnitude; }
	float dot(const vec3& rhs) const;
	vec3  cross(const vec3& b) const;

	vec3 normalize() const {
		return vec3{
			x() / _magnitude,
			y() / _magnitude,
			z() / _magnitude
		};
	}

private:
	float _magnitude;
};

vec3::vec3(float x, float y, float z) : tuple(x, y, z, 0.0f) {
	_magnitude = sqrt(vec3::x() * vec3::x() + vec3::y() * vec3::y() + vec3::z() * vec3::z());
}

vec3::vec3(tuple t) : vec3(t.x(), t.y(), t.z()) {
	std::cout << "vec3 tuple convert" << std::endl;
}

inline
vec3 operator+(const vec3& lhs, const vec3& rhs) {
	return vec3{
		(tuple)(lhs) + tuple(rhs)
	};
}

inline
vec3 operator-(const vec3& lhs, const vec3& rhs) {
	return vec3{ (tuple)lhs - (tuple)rhs};
}

inline vec3 operator-(const vec3& element) {
	return vec3{ -(tuple)element };
}

float vec3::dot(const vec3& b) const
{
	return	x() * b.x() +
			y() * b.y() +
			z() * b.z();
}

vec3 vec3::cross(const vec3& b) const
{
	return vec3{ this->y() * b.z() - this->z() * b.y(),
				 this->z() * b.x() - this->x() * b.z(),
				 this->x() * b.y() - this->y() * b.x()
	};
}