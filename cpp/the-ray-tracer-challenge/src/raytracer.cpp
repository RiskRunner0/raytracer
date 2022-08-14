// RayTracerChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"
#include "point3.h"
#include "PPMFileWriter.h"
#include "Translation.h"
#define _USE_MATH_DEFINES
#include <math.h>

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
    point3 position = p.position + p.velocity;
    vec3 velocity = p.velocity + e.gravity + e.wind;
    return projectile{ position, velocity };
}


int main()
{
    // create new canvas
    Canvas c{ 100, 100 };

    Color white{255, 255, 255};

    auto translate = translation(50, 50, 0);
    auto rotate = rotation_z((float)M_PI / 6.0f);
    point3 mid{ 50, 50, 0 };
    point3 curr{ 0, 25, 0 };

    for (int i = 0; i < 12; ++i) {
        auto moved = translate * curr;
        c.writePixel(moved.x(), moved.y(), white);
        curr = rotate * curr;
    }

    PPMFileWriter fileWriter{};
    fileWriter.WriteToPPMFile(c, "clock.ppm");
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
