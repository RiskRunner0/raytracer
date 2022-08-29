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
    floor->SetTransformation(new Matrix{ scaling(10, 0.01, 10) });
    Material* mat = new Material{};
    mat->color = Color{ 1.0, 0.9, 0.9 };
    mat->specular = 0;
    floor->SetMaterial(mat);

    Sphere* leftWall = new Sphere{};
    leftWall->SetTransformation(new Matrix{
        translation(0, 0, 5) *
        rotation_y(-static_cast<float>(M_PI) / 4.0f) *
        rotation_x(static_cast<float>(M_PI) / 2.0f) *
        scaling(10, 0.01, 10)
    });

    Sphere* rightWall = new Sphere{};
    rightWall->SetTransformation(new Matrix{
        translation(0, 0, 5) *
        rotation_y(static_cast<float>(M_PI) / 4.0f) *
        rotation_x(static_cast<float>(M_PI) / 2.0f) *
        scaling(10, 0.01, 10)
    });

    Sphere* middle = new Sphere{};
    middle->SetTransformation(new Matrix{ translation(-0.5, 1, 0.5) });
    Material* midMat = new Material{};
    midMat->color = Color{ 0.1, 1.0, 0.5 };
    midMat->diffuse = 0.7;
    midMat->specular = 0.3;
    middle->SetMaterial(midMat);

    Sphere* right = new Sphere{};
    right->SetTransformation(new Matrix{translation(1.5, 0.5, -0.5) * scaling(0.5, 0.5, 0.5)});
    Material* rightMat = new Material();
    rightMat->color = Color{ 0.5, 1.0, 0.1 };
    rightMat->diffuse = 0.7;
    rightMat->specular = 0.3;
    right->SetMaterial(rightMat);

    Sphere* left = new Sphere{};
    left->SetTransformation(new Matrix{translation(-1.5, 0.33, -0.75) * scaling(0.33, 0.33, 0.33)});
    left->GetMaterial()->color = Color{1.0, 0.8, 0.1};
    left->GetMaterial()->diffuse = 0.7;
    left->GetMaterial()->specular = 0.3;

    std::vector<Shape*> spheres{left, right, middle, rightWall, leftWall, floor};
    PointLight pointLight{ point3{-10, 10, -10}, Color{1, 1, 1} };
    World world{ pointLight, spheres };

    Camera camera{ 500, 250, static_cast<float>(M_PI) / 3.0f };
    camera.transformation = new Matrix{
        viewTransformation(
            point3{0.0, 1.5, -5.0},
            point3{0, 1, 0},
            vec3{0, 1, 0})
    };

    Canvas c = render(camera, world);

    PPMFileWriter writer;
    writer.WriteToPPMFile(c, "doesitwork.ppm");

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
