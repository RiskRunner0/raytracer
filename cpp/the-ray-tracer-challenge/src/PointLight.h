#pragma once

#include "point3.h"
#include "Color.h"
#include "Material.h"

class PointLight {
public:
	PointLight(point3 position, Color intensity);

	Color  Intensity() const;
	point3 Position() const;

private:
	Color _intensity;
	point3 _position;
};

Color lighting(Material& m, PointLight& light, point3& position, vec3& eyeV, vec3& normalV);