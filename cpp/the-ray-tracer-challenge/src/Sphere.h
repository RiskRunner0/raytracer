#pragma once

#include "point3.h"
#include "Matrix.h"
#include "vec3.h"
#include "Material.h"
#include "Math.h"
#include "Shape.h"

class Sphere : public Shape {
public:
	Sphere();

	virtual Matrix*   GetTransformation();
	virtual Matrix*   GetTransformation() const;
	virtual void      SetTransformation(Matrix* m);
	virtual Material* GetMaterial();
	virtual Material* GetMaterial() const;
	virtual void      SetMaterial(Material* mat);
	virtual bool      isEqual(const Shape& shape);

	float  radius;
	point3 center;

protected:
	Matrix*   _transformation;
	Material* _material;

private:
	Matrix*	  _getTransformation() const;
	Material* _getMaterial() const;
};

vec3 normalAt(Shape& s, point3 worldPoint);