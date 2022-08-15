// RayTracerChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "vec3.h"
#include "point3.h"
#include "PPMFileWriter.h"
#include "Translation.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Sphere.h"
#include "Intersection.h"

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
    Sphere s{};
    auto transform = translation(500, 500, 0) * scaling(25, 25, 25);
    s.SetTransformation(transform);

    Canvas c{ 1000, 1000 };
    Color red{ 255, 0, 0 };

    point3 rayPoint{ 500, 500, 300 };

    for (int row = 0; row < c.height(); ++row) {
        for (int col = 0; col < c.width(); ++col) {
            point3 pointOnCanvas{ row, col, 0 };
            vec3 vectToCanvas{ pointOnCanvas - rayPoint };

            ray r{ rayPoint, vectToCanvas };
            auto xs = intersect(s, r);
            if (xs.size() > 0) {
                // std::cout << "HIT AT " << row << ", " << col << std::endl;
                c.writePixel(row, col, red);
            }
        }
    }

    PPMFileWriter writer;
    writer.WriteToPPMFile(c, "circle.ppm");

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
