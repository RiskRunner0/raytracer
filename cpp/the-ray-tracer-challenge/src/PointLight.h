#pragma once

#include "point3.h"
#include "Color.h"
#include "Material.h"

class PointLight {
public:
	PointLight(point3 position, Color intensity);


	Color intensity;
	point3 position;
};

Color lighting(Material& m, PointLight& light, point3& position, vec3& eyeV, vec3& normalV);

inline
bool operator==(const PointLight& lhs, const PointLight& rhs) {
	return lhs.intensity == rhs.intensity && lhs.position == rhs.position;
}