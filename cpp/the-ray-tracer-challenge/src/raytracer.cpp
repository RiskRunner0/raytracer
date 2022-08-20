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

int main()
{
    Sphere s{};
    Material m{ Color{1.0, 0.2, 1.0}, MATERIAL_DEFAULT_AMBIENT, MATERIAL_DEFAULT_DIFFUSE, MATERIAL_DEFAULT_SPECULAR, MATERIAL_DEFAULT_SHININESS };
    s.SetMaterial(m);
    
    // set light
    point3 lightPosition{ -10, 10, -10 };
    Color lightColor{ 1.0, 1.0, 1.0 };
    PointLight light{ lightPosition, lightColor };

    point3 rayPoint{ 0, 0, -5 };
    auto wallZ = 10.0;
    auto wallSize = 7.0;
    auto canvasPixels = 100;

    auto pixelSize = wallSize / canvasPixels;
    auto half = wallSize / 2.0;

    Canvas c{ canvasPixels, canvasPixels };

    for (int row = 0; row < c.height(); ++row) {

        auto worldY = half - pixelSize * row;
        for (int col = 0; col < c.width(); ++col) {
            auto worldX = -half + pixelSize * col;
            //std::cout << "PROCESSING " << row << ", " << col << std::endl;
            point3 pos{ worldX, worldY, wallZ };

            ray r{ rayPoint, normalize(pos - rayPoint)};
            auto xs = intersect(s, r);
            if (xs.size() > 0) {
                // std::cout << "HIT AT " << row << ", " << col << std::endl;
                // Color color{ 255, 0, 0 };
                auto p = position(r, xs[0].t);
                auto normal = normalAt(s, p);
                auto eye = -r.Direction();
                auto color = lighting(m, light, p, eye, normal);
                c.writePixel(row, col, color);
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
