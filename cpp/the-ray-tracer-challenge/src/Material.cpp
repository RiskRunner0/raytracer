#include "Material.h"

Material::Material(Color color, float ambient, float diffuse, float specular, float shininess) :
	_color(color), _ambient(ambient), _diffuse(diffuse), _specular(specular), _shininess(shininess)
{}

Material::Material() : Material(
	MATERIAL_DEFAULT_COLOR, 
	MATERIAL_DEFAULT_AMBIENT,
	MATERIAL_DEFAULT_DIFFUSE,
	MATERIAL_DEFAULT_SPECULAR,
	MATERIAL_DEFAULT_SHININESS)
{}

Color Material::GetColor() const
{
	return _color;
}

float Material::Ambient() const
{
	return _ambient;
}

float Material::Diffuse() const
{
	return _diffuse;
}

float Material::Specular() const
{
	return _specular;
}

float Material::Shininess() const
{
	return _shininess;
}