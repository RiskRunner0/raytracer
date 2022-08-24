#pragma once

#include "Matrix.h"
#include "Ray.h"
#include "Canvas.h"
#include "World.h"

class Camera {
public:
	Camera(int hsize, int vsize, float fieldOfView);
	int		hsize;
	int		vsize;
	float	fieldOfView;
	Matrix* transformation;
	float	pixelSize;
	float	halfHeight;
	float	halfWidth;

private:
	void calculatePixelSize();
};

ray rayForPixel(const Camera& c, float px, float py);

Canvas render(Camera camera, World world);