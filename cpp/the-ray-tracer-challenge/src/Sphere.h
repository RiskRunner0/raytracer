#pragma once

#include "point3.h"
#include "Object.h"
#include "Matrix.h"
#include "vec3.h"
#include "Material.h"

class Sphere : public Object {
public:
	Sphere();

	float    Radius() const;
	point3   Center() const;
	const    Matrix* Transformation() const;
	void     SetTransformation(const Matrix& m);
	Material GetMaterial() const;
	void	 SetMaterial(Material& m);
private:
	float    _radius;
	point3   _center;
	Matrix*  _transformation;
	Material _material;
};

vec3 normalAt(Sphere s, point3 p);