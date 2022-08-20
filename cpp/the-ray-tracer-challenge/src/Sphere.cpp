#include "Sphere.h"

Sphere::Sphere() : 
	_radius(1.0f),
	_center(point3{ 0, 0, 0 }),
	_transformation(new Matrix{ IdentityMatrix4x4 }),
	_material(Material{})
{}

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

Material Sphere::GetMaterial() const {
	return _material;
}

void Sphere::SetMaterial(Material& m) {
	_material = m;
}

vec3 normalAt(Sphere s, point3 worldPoint) {
	const Matrix* transformM = s.Transformation();
	Matrix* inverseM = inverse(*transformM);
	auto objectPoint = *inverse(*s.Transformation()) * worldPoint;
	auto objectNormal = objectPoint - point3{ 0, 0, 0 };
	auto worldNormal = transpose(*inverseM) * objectNormal;

	// clean up pointers
	//delete transformM;
	//delete inverseM;

	return normalize(worldNormal);
}