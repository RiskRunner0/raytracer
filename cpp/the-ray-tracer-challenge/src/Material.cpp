#include "Material.h"

Material::Material(Color color, float ambient, float diffuse, float specular, float shininess) :
	color(color), ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess)
{}

Material::Material() : Material(
	MATERIAL_DEFAULT_COLOR, 
	MATERIAL_DEFAULT_AMBIENT,
	MATERIAL_DEFAULT_DIFFUSE,
	MATERIAL_DEFAULT_SPECULAR,
	MATERIAL_DEFAULT_SHININESS)
{}