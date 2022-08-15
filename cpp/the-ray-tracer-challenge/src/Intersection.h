#pragma once

#include "Object.h"
#include <vector>
#include <cstdarg>
#include "Math.h"

class Intersection {
public:
	Intersection(float t, Object& o);

	float t;
	Object* object;
};

inline
bool operator==(const Intersection& lhs, const Intersection& rhs) {
	bool closeT = floatEqual(lhs.t, rhs.t);
	auto lhsRef = lhs.object;
	auto rhsRef = rhs.object;
	return closeT && lhsRef == rhsRef;
}

std::vector<Intersection> intersections(std::vector<Intersection>& ints);

Intersection* hit(std::vector<Intersection>& ints);