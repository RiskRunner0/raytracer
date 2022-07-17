#pragma once

#ifndef COLOR_H
#define COLOR_H

#include "Math.h"

class Color {
public:
	Color() : e{0, 0, 0} {}
	Color(float r, float g, float b) : e{r, g, b} {}

	float r() const { return e[0]; }
	float g() const { return e[1]; }
	float b() const { return e[2]; }

private:
	float e[3];
};

inline
bool operator==(const Color& lhs, const Color& rhs) {
	return floatEqual(lhs.r(), rhs.r()) && floatEqual(lhs.g(), rhs.g()) && floatEqual(lhs.b(), rhs.b());
}

inline
Color operator+(const Color& a, const Color& b) {
	return Color{ a.r() + b.r(), a.g() + b.g(), a.b() + b.b() };
}

inline
Color operator-(const Color& a, const Color& b) {
	return Color{ a.r() - b.r(), a.g() - b.g(), a.b() - b.b() };
}

inline
Color operator*(const Color& a, const Color& b) {
	return Color{ a.r() * b.r(), a.g() * b.g(), a.b() * b.b() };
}

inline
Color operator*(const Color& a, float scalar) {
	return Color{ a.r() * scalar, a.g() * scalar, a.b() * scalar };
}

#endif // !COLOR_H
