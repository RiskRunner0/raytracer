#pragma once

#include "Math.h"

class Color {
public:
	Color();
	Color(float r, float g, float b);

	float r() const;
	float g() const;
	float b() const;

	bool  operator==(const Color& rhs) const;
	Color operator+(const Color& rhs) const;
	Color operator-(const Color& rhs) const;
	Color operator*(const Color& rhs) const;
	Color operator*(float) const;

private:
	float e[3];
};