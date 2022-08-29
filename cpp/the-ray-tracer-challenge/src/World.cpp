#include "World.h"

World::World(PointLight light, std::vector<Shape*> spheres) : light(light), spheres(spheres) {}

World MakeDefaultWorld() {

	 PointLight light{ point3{-10, 10, -10}, Color{1, 1, 1} };

	 Sphere s1{};
	 Material* m = new Material{};
	 m->color = Color{ 0.8f, 1.0f, 0.6f };
	 m->diffuse = 0.7f;
	 m->specular = 0.2f;
	 s1.SetMaterial(m);

	 Sphere s2{};
	 s2.SetTransformation(new Matrix{ scaling(0.5, 0.5, 0.5) });

	 std::vector<Shape*> vec{};
	 vec.push_back(new Sphere(s1));
	 vec.push_back(new Sphere(s2));
	 World w{ light, vec };

	 return w;
}


std::vector<Intersection> intersectWorld(const World& w, ray& r) {
	std::vector<Intersection> result{};

	for (int i = 0; i < w.spheres.size(); ++i) {
		Shape* el = w.spheres[i];

		auto ints = intersect(el, r);

		for (int j = 0; j < ints.size(); ++j) {
			result.push_back(ints[j]);
		}
	}

	// sort
	std::sort(result.begin(), result.end(), [](const Intersection& a, const Intersection& b) -> bool {
		return a.t < b.t;
	});

	return result;
}

PreparedComputations prepareComputations(Intersection& i, ray& r) {
	PreparedComputations comps;
	
	comps.t = i.t;
	comps.object = i.object;
	comps.point = position(r, comps.t);
	comps.eyeV = -r.direction;
	comps.normalV = normalAt(*comps.object, comps.point);

	if (dot(comps.normalV, comps.eyeV) < 0) {
		comps.inside = true;
		comps.normalV = -comps.normalV;
	}

	comps.overPoint = comps.point + comps.normalV * EPSILON;

	return comps;
}

Color shadeHit(World world, PreparedComputations comps) {
	bool isShadow = isShadowed(world, comps.overPoint);
	return lighting(*comps.object->GetMaterial(), world.light, comps.overPoint, comps.eyeV, comps.normalV, isShadow);
}

Color colorAt(World& world, ray& r) {
	auto inter = intersectWorld(world, r);

	auto hits = hit(inter);

	if (hits == nullptr) return Color{ 0, 0, 0 };

	auto precomp = prepareComputations(*hits, r);

	auto retVal = shadeHit(world, precomp);

	return retVal;
}

bool isShadowed(World world, point3 point) {
	vec3 v = world.light.position - point;
	auto distance = v.magnitude();
	auto direction = normalize(v);

	ray r{ point, direction };
	auto intersections = intersectWorld(world, r);
	
	auto h = hit(intersections);

	return h != nullptr && h->t < distance;
}