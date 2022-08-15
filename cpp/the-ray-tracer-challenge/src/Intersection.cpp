#include "Intersection.h"

Intersection::Intersection(float t, Object& o) : t(t), object(&o) {}

std::vector<Intersection> intersections(std::vector<Intersection>& ints) {
	return ints;
}

Intersection* hit(std::vector<Intersection>& ints) {
	Intersection* result = nullptr;

	for (int i = 0; i < ints.size(); ++i) {
		Intersection el = ints[i];
		bool shouldReplace = el.t > 0 && (result == nullptr || result->t > el.t);
		if (shouldReplace) {
			result = &ints[i];
		}
	}

	return result;
}