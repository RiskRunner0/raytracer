#include "tuple.h"

tuple::tuple(float x, float y, float z, float w) : _e{ x, y, z, w }
{
};

tuple::tuple(const tuple& t) : tuple(t.x(), t.y(), t.z(), t.w())
{
	std::cout << "tuple copy" << std::endl;
};

float tuple::x() const { return _e[0]; };
float tuple::y() const { return _e[1]; };
float tuple::z() const { return _e[2]; };
float tuple::w() const { return _e[3]; };

tuple tuple::operator+(const tuple& rhs) const
{
	return tuple{
		x() + rhs.x(),
		y() + rhs.y(),
		z() + rhs.z(),
		w() + rhs.w()
	};
}

bool tuple::operator==(const tuple& rhs) const
{
	return floatEqual(x(), rhs.x())
		&& floatEqual(y(), rhs.y())
		&& floatEqual(z(), rhs.z())
		&& floatEqual(w(), rhs.w());
}

tuple tuple::operator-(const tuple& rhs) const
{
	return tuple{
		x() - rhs.x(),
		y() - rhs.y(),
		z() - rhs.z(),
		w() - rhs.w()
	};
}

tuple tuple::operator-() const
{
	return tuple{
		-x(),
		-y(),
		-z(),
		-w()
	};
}

tuple tuple::operator*(float rhs) const
{
	return tuple{
		x() * rhs,
		y() * rhs,
		z() * rhs,
		w() * rhs
	};
}

tuple tuple::operator/(float rhs) const
{
	return tuple{
		x() / rhs,
		y() / rhs,
		z() / rhs,
		w() / rhs
	};
}