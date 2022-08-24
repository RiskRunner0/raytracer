#include "World.h"

World::World(PointLight light, std::vector<Sphere*> spheres) : light(light), spheres(spheres) {}

World MakeDefaultWorld() {

	 PointLight light{ point3{-10, 10, -10}, Color{1, 1, 1} };

	 Sphere s1{};
	 Material m{};
	 m.color = Color{ 0.8f, 1.0f, 0.6f };
	 m.diffuse = 0.7f;
	 m.specular = 0.2f;
	 s1.material = m;

	 Sphere s2{};
	 s2.transformation = new Matrix{ scaling(0.5, 0.5, 0.5) };

	 std::vector<Sphere*> vec{};
	 vec.push_back(new Sphere(s1));
	 vec.push_back(new Sphere(s2));
	 World w{ light, vec };

	 return w;
}


std::vector<Intersection> intersectWorld(const World& w, ray& r) {
	std::vector<Intersection> result{};

	for (int i = 0; i < w.spheres.size(); ++i) {
		Sphere* el = w.spheres[i];

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

	return comps;
}

Color shadeHit(World world, PreparedComputations comps) {
	return lighting(comps.object->material, world.light, comps.point, comps.eyeV, comps.normalV);
}

Color colorAt(World& world, ray& r) {
	auto inter = intersectWorld(world, r);

	auto hits = hit(inter);

	if (hits == nullptr) return Color{ 0, 0, 0 };

	auto precomp = prepareComputations(*hits, r);

	auto retVal = shadeHit(world, precomp);

	return retVal;
}