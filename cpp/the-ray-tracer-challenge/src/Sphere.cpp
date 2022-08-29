#include "Sphere.h"

Sphere::Sphere() : 
	radius(1.0f),
	center(point3{ 0, 0, 0 }),
	_transformation(new Matrix{ IdentityMatrix4x4 }),
	_material(new Material{})
{}

Matrix* Sphere::_getTransformation() const {
	return _transformation;
}

Matrix* Sphere::GetTransformation() {
	return _getTransformation();
}

Matrix* Sphere::GetTransformation() const {
	return _getTransformation();
}

void Sphere::SetTransformation(Matrix* m) {
	_transformation = m;
}

Material* Sphere::_getMaterial() const {
	return _material;
}

Material* Sphere::GetMaterial() {
	return _getMaterial();
}

Material* Sphere::GetMaterial() const {
	return _getMaterial();
}

void Sphere::SetMaterial(Material* mat) {
	_material = mat;
}

vec3 normalAt(Shape& s, point3 worldPoint) {
	const Matrix* transformM = s.GetTransformation();
	Matrix* inverseM = inverse(*transformM);
	auto objectPoint = *inverse(*s.GetTransformation()) * worldPoint;
	auto objectNormal = objectPoint - point3{ 0, 0, 0 };
	auto worldNormal = transpose(*inverseM) * objectNormal;

	// clean up pointers
	//delete transformM;
	//delete inverseM;

	return normalize(worldNormal);
}

bool Sphere::isEqual(const Shape& shape) {
	const Shape* ptr = &shape;
	const Sphere* asSphere = dynamic_cast<const Sphere*>(ptr);

	return asSphere != nullptr && floatEqual(radius, asSphere->radius) &&
		center == asSphere->center &&
		*GetTransformation() == *asSphere->GetTransformation()
		&& *GetMaterial() == *asSphere->GetMaterial();
}