#pragma once

#include "Math.h"
#include <iostream>

class tuple {
public:
	tuple(float x, float y, float z, float w);
	tuple(const tuple& t);

	virtual float x() const;
	virtual float y() const;
	virtual float z() const;
	virtual float w() const;

	tuple operator+(const tuple& rhs) const;
	bool  operator==(const tuple& rhs) const;
	tuple operator-(const tuple& b) const;
	tuple operator-() const;
	tuple operator*(float rhs) const;
	tuple operator/(float rhs) const;


protected:
	float _e[4]{};
};