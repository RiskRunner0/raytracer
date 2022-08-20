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

	Color GetColor() const;
	float Ambient() const;
	float Diffuse() const;
	float Specular() const;
	float Shininess() const;

private:
	Color _color;
	float _ambient;
	float _diffuse;
	float _specular;
	float _shininess;
};

inline
bool operator==(const Material& lhs, const Material& rhs) {
	return lhs.GetColor() == rhs.GetColor() &&
		floatEqual(lhs.Ambient(), rhs.Ambient()) &&
		floatEqual(lhs.Diffuse(), rhs.Diffuse()) &&
		floatEqual(lhs.Specular(), rhs.Specular()) &&
		floatEqual(lhs.Shininess(), rhs.Shininess());
}