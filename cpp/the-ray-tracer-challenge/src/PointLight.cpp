#include "PointLight.h"

PointLight::PointLight(point3 position, Color intensity) : _position(position), _intensity(intensity)
{}

Color PointLight::Intensity() const {
	return _intensity;
}

point3 PointLight::Position() const {
	return _position;
}

Color lighting(Material& m, PointLight& light, point3& position, vec3& eyeV, vec3& normalV) {
	// combine the surface color with the light's color/intensity
	Color effectiveColor = m.GetColor() * light.Intensity();

	// find the direction to the light source
	vec3 lightV = normalize(light.Position() - position);

	// compute the ambient contribution
	Color ambient = effectiveColor * m.Ambient();

	// represents the cosine of the angle between the light vector and
	// the normal vector. Negative number means light is on the other
	// side of the surface.
	float lightDotNormal = dot(lightV, normalV);

	Color diffuse;
	Color specular;
	if (lightDotNormal < 0) {
		diffuse = Color{ 0, 0, 0 };
		specular = Color{ 0, 0, 0 };
	}
	else {
		// compute the diffuse contribution
		diffuse = effectiveColor * m.Diffuse() * lightDotNormal;

		auto reflectV = reflect(-lightV, normalV);
		auto reflectDotEye = dot(reflectV, eyeV);

		if (reflectDotEye < 0) {
			specular = Color{ 0, 0, 0 };
		}
		else {
			// compute the specular contribution
			auto factor = pow(reflectDotEye, m.Shininess());
			specular = light.Intensity() * m.Specular() * factor;
		}
	}

	return ambient + diffuse + specular;
}