#include "Sphere.h"

Sphere::Sphere() : 
	radius(1.0f),
	center(point3{ 0, 0, 0 }),
	transformation(new Matrix{ IdentityMatrix4x4 }),
	material(Material{})
{}

vec3 normalAt(Sphere s, point3 worldPoint) {
	const Matrix* transformM = s.transformation;
	Matrix* inverseM = inverse(*transformM);
	auto objectPoint = *inverse(*s.transformation) * worldPoint;
	auto objectNormal = objectPoint - point3{ 0, 0, 0 };
	auto worldNormal = transpose(*inverseM) * objectNormal;

	// clean up pointers
	//delete transformM;
	//delete inverseM;

	return normalize(worldNormal);
}