#pragma once

#include "Color.h"
#include "Math.h"

#define MATERIAL_DEFAULT_COLOR     Color{1, 1, 1}
#define MATERIAL_DEFAULT_AMBIENT   0.1f
#define MATERIAL_DEFAULT_DIFFUSE   0.9f
#define MATERIAL_DEFAULT_SPECULAR  0.9f
#define MATERIAL_DEFAULT_SHININESS 200.0f

class Material {
public:
	Material();

	Material(
		Color color,
		float ambient,
		float diffuse,
		float specular,
		float shininess);

	Color color;
	float ambient;
	float diffuse;
	float specular;
	float shininess;

};

inline
bool operator==(const Material& lhs, const Material& rhs) {
	return lhs.color == rhs.color &&
		floatEqual(lhs.ambient, rhs.ambient) &&
		floatEqual(lhs.diffuse, rhs.diffuse) &&
		floatEqual(lhs.specular, rhs.specular) &&
		floatEqual(lhs.shininess, rhs.shininess);
}