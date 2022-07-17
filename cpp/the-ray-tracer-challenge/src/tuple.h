#pragma once

#include "Math.h"
#include <iostream>

class tuple {
public:
	tuple(float x, float y, float z, float w);
	tuple(const tuple& t);

	virtual float x() const { return _e[0]; };
	virtual float y() const { return _e[1]; };
	virtual float z() const { return _e[2]; };
	virtual float w() const { return _e[3]; };

protected:
	float _e[4]{};
};

inline
tuple::tuple(float x, float y, float z, float w) : _e{ x, y, z, w } {};

inline
tuple::tuple(const tuple& t) : tuple(t.x(), t.y(), t.z(), t.w()) {
	std::cout << "tuple copy" << std::endl;
};

inline
tuple operator+(const tuple& lhs, const tuple& rhs) {
	return tuple{
		lhs.x() + rhs.x(),
		lhs.y() + rhs.y(),
		lhs.z() + rhs.z(),
		lhs.w() + rhs.w()
	};
}

inline
bool operator==(const tuple& lhs, const tuple& rhs) {
	return floatEqual(lhs.x(), rhs.x())
		&& floatEqual(lhs.y(), rhs.y())
		&& floatEqual(lhs.z(), rhs.z())
		&& floatEqual(lhs.w(), rhs.w());
}

inline tuple operator-(const tuple& a, const tuple& b) {
	return tuple{
		a.x() - b.x(),
		a.y() - b.y(),
		a.z() - b.z(),
		a.w() - b.w()
	};
}

inline tuple operator-(const tuple& a)
{
	return tuple{
		-a.x(),
		-a.y(),
		-a.z(),
		-a.w()
	};
}

inline tuple operator*(const tuple& lhs, float rhs) {
	return tuple{
		lhs.x() * rhs,
		lhs.y() * rhs,
		lhs.z() * rhs,
		lhs.w() * rhs
	};
}

inline tuple operator/(const tuple& lhs, float rhs) {
	return tuple{
		lhs.x() / rhs,
		lhs.y() / rhs,
		lhs.z() / rhs,
		lhs.w() / rhs
	};
}