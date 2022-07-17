#include "Color.h"

Color::Color() : e{ 0, 0, 0 } {};

Color::Color(float r, float g, float b) : e{ r, g, b } {}

float Color::r() const { return e[0]; }

float Color::g() const { return e[1]; }

float Color::b() const { return e[2]; }

bool Color::operator==(const Color& rhs) const {
	return floatEqual(r(), rhs.r())
		&& floatEqual(g(), rhs.g())
		&& floatEqual(b(), rhs.b());
}

Color Color::operator+(const Color& rhs) const {
	return Color{ r() + rhs.r(), g() + rhs.g(), b() + rhs.b() };
}

Color Color::operator-(const Color& rhs) const {
	return Color{ r() - rhs.r(), g() - rhs.g(), b() - rhs.b() };
}

Color Color::operator*(const Color& rhs) const {
	return Color{ r() * rhs.r(), g() * rhs.g(), b() * rhs.b() };
}

Color Color::operator*(float scalar) const {
	return Color{ r() * scalar, g() * scalar, b() * scalar };
}