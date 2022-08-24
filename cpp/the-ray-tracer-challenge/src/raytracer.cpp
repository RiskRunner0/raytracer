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
#include "PointLight.h"
#include "World.h"
#include "Camera.h"

int main()
{
    Sphere* floor = new Sphere{};
    floor->transformation = new Matrix{ scaling(10, 0.01, 10) };
    floor->material.color = Color{ 1.0, 0.9, 0.9 };
    floor->material.specular = 0;

    Sphere* leftWall = new Sphere{};
    leftWall->transformation = new Matrix{
        translation(0, 0, 5) *
        rotation_y(-static_cast<float>(M_PI) / 4.0f) *
        rotation_x(static_cast<float>(M_PI) / 2.0f) *
        scaling(10, 0.01, 10)
    };

    Sphere* rightWall = new Sphere{};
    rightWall->transformation = new Matrix{
        translation(0, 0, 5) *
        rotation_y(static_cast<float>(M_PI) / 4.0f) *
        rotation_x(static_cast<float>(M_PI) / 2.0f) *
        scaling(10, 0.01, 10)
    };

    Sphere* middle = new Sphere{};
    middle->transformation = new Matrix{ translation(-0.5, 1, 0.5) };
    middle->material.color = Color{ 0.1, 1.0, 0.5 };
    middle->material.diffuse = 0.7;
    middle->material.specular = 0.3;

    Sphere* right = new Sphere{};
    right->transformation = new Matrix{ translation(1.5, 0.5, -0.5)  * scaling(0.5, 0.5, 0.5)};
    right->material.color = Color{ 0.5, 1.0, 0.1 };
    right->material.diffuse = 0.7;
    right->material.specular = 0.3;

    Sphere* left = new Sphere{};
    left->transformation = new Matrix{ translation(-1.5, 0.33, -0.75) * scaling(0.33, 0.33, 0.33) };
    left->material.color = Color{ 1.0, 0.8, 0.1 };
    left->material.diffuse = 0.7;
    left->material.specular = 0.3;

    std::vector<Sphere*> spheres{left, right, middle, rightWall, leftWall, floor};
    PointLight pointLight{ point3{-10, 10, -10}, Color{1, 1, 1} };
    World world{ pointLight, spheres };

    Camera camera{ 1000, 500, static_cast<float>(M_PI) / 3.0f };
    camera.transformation = new Matrix{
        viewTransformation(
            point3{0.0, 1.5, -5.0},
            point3{0, 1, 0},
            vec3{0, 1, 0})
    };

    Canvas c = render(camera, world);

    PPMFileWriter writer;
    writer.WriteToPPMFile(c, "chapter7.ppm");

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
