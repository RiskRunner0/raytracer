#pragma once

#include <math.h>

#define EPSILON static_cast<float>(0.00001)

inline bool floatEqual(float a, float b) {
	auto diff = fabsf(a - b);
	return  diff < EPSILON;
}
