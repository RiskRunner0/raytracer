#include "Ray.h"

ray::ray(point3 origin, vec3 direction) : _origin(origin), _direction(direction)
{}

point3 ray::Origin() const {
	return _origin;
}

vec3 ray::Direction() const {
	return _direction;
}

point3 position(ray r, float t) {
	return r.Origin() + r.Direction() * t;
}

std::vector<Intersection> intersect(Sphere& s, ray& r) {
	Matrix* inverseMat = inverse(*s.Transformation());
	ray r2 = transform(r, *inverseMat);
	delete inverseMat;

	auto sphereToRay = r2.Origin() - point3{ 0, 0, 0 };

	auto a = r2.Direction().dot(r2.Direction());
	auto b = 2 * r2.Direction().dot(sphereToRay);
	auto c = sphereToRay.dot(sphereToRay) - 1;

	auto discriminant = b * b - 4 * a * c;

	std::vector<Intersection> result{};
	if (discriminant < 0) {
		return result;
	}

	auto t1 = (-b - sqrt(discriminant)) / (2 * a);
	auto t2 = (-b + sqrt(discriminant)) / (2 * a);

	result.push_back({ t1, s });
	result.push_back({ t2, s });
	return result;
}

ray transform(ray& r, Matrix& m) {
	return ray{m * r.Origin(), m * r.Direction()};
}