#pragma once

#ifndef MATH_H
#define MATH_H

#include <math.h>

#define EPSILON 0.00001;

inline bool floatEqual(float a, float b) {
	return abs(a - b) < EPSILON;
}

#endif // !MATH_H
