#pragma once

#include <math.h>

#define EPSILON 0.00001;

inline bool floatEqual(float a, float b) {
	auto diff = fabsf(a - b);
	return  diff < EPSILON;
}
