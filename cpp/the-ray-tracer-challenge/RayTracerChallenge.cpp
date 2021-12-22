// RayTracerChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"

class projectile {
public:
    projectile(point3 position, vec3 velocity) : position(position), velocity(velocity) {}
    point3 position;
    vec3 velocity;
};

class environment {
public:
    environment(vec3 g, vec3 w) : gravity(g), wind(w) {}
    vec3 gravity;
    vec3 wind;
};

projectile tick(environment e, projectile p)
{
    auto position = p.position + p.velocity;
    auto velocity = p.velocity + e.gravity + e.wind;
    return projectile{ position, velocity };
}


int main()
{
    projectile proj{ point3{0, 1, 0}, vec3{1, 1, 0}.normalize() };

    environment env{ vec3{0, -0.1, 0}, vec3{-0.01, 0, 0} };

    while (proj.position.y() > 0)
    {
        std::cout << "Position: " << proj.position.y() << std::endl;
        proj = tick(env, proj);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
