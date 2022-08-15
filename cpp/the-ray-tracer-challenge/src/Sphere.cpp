#include "Sphere.h"

Sphere::Sphere() : _radius(1.0f), _center(point3{ 0, 0, 0 }), _transformation(new Matrix{ IdentityMatrix4x4 }) {}

float Sphere::Radius() const {
	return _radius;
}

point3 Sphere::Center() const {
	return _center;
}

void Sphere::SetTransformation(const Matrix& m) {
	_transformation = new Matrix{ m };
}

const Matrix* Sphere::Transformation() const {
	return _transformation;
}