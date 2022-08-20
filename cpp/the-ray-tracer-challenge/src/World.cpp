#include "World.h"
#include "Translation.h"

World::World(PointLight light, std::vector<Sphere> spheres) : light(light), spheres(spheres) {}

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

 std::vector<Sphere> vec{};
 vec.push_back(s1);
 vec.push_back(s2);
 World w{ light, vec };

 return w;
}