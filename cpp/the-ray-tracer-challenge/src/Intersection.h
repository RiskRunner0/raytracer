#pragma once

#include <vector>
#include <cstdarg>
#include "Math.h"
#include "Shape.h"

class Intersection {
public:
	Intersection(float t, Shape* o);

	float t;
	Shape* object;
};

inline
bool operator==(const Intersection& lhs, const Intersection& rhs) {
	bool closeT = floatEqual(lhs.t, rhs.t);
	auto lhsRef = lhs.object;
	auto rhsRef = rhs.object;
	return closeT && lhsRef->isEqual(*rhsRef);
}

std::vector<Intersection> intersections(std::vector<Intersection>& ints);

Intersection* hit(std::vector<Intersection>& ints);