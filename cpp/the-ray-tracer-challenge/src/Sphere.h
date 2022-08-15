#pragma once

#include "point3.h"
#include "Object.h"
#include "Matrix.h"

class Sphere : public Object {
public:
	Sphere();

	float  Radius() const;
	point3 Center() const;
	const  Matrix* Transformation() const;
	void   SetTransformation(const Matrix& m);
private:
	float   _radius;
	point3  _center;
	Matrix* _transformation;
};