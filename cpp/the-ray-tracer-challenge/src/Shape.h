#pragma once

#include "Matrix.h"
#include "Material.h"

class Shape {
public:
	virtual Matrix* GetTransformation() = 0;
	virtual Matrix* GetTransformation() const = 0;
	virtual void SetTransformation(Matrix* m) = 0;
	virtual Material* GetMaterial() = 0;
	virtual void SetMaterial(Material* mat) = 0;
	virtual bool isEqual(const Shape& shape) = 0;
};