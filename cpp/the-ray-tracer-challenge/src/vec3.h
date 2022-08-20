#pragma once

#include "Math.h"
#include "tuple.h"

#include <iostream>

class vec3 : public tuple {
public:
	vec3(float x, float y, float z);

	vec3(tuple t);

	float magnitude() const;
	vec3  cross(const vec3& b) const;

	vec3 operator+(const vec3& rhs) const;
	vec3 operator-(const vec3& rhs) const;
	vec3 operator-() const;

private:
	float _magnitude;
};

float dot(const vec3& lhs, const vec3& rhs);
vec3 normalize(const vec3& v);
vec3 reflect(const vec3& v, const vec3& normal);
