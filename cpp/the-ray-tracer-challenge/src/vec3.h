#pragma once

#include "Math.h"
#include "tuple.h"

#include <iostream>

class vec3 : public tuple {
public:
	vec3(float x, float y, float z);

	vec3(tuple t);

	float magnitude() const;
	float dot(const vec3& rhs) const;
	vec3  cross(const vec3& b) const;
	vec3 normalize() const;

	vec3 operator+(const vec3& rhs) const;
	vec3 operator-(const vec3& rhs) const;
	vec3 operator-() const;

private:
	float _magnitude;
};
