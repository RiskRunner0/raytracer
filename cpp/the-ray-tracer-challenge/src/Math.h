#pragma once

#include <math.h>

#define EPSILON 0.00001;

inline bool floatEqual(float a, float b) {
	return fabsf(a - b) < EPSILON;
}
