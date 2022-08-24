#include "Camera.h"

Camera::Camera(int hsize, int vsize, float fieldOfView) : 
	hsize(hsize), 
	vsize(vsize), 
	fieldOfView(fieldOfView),
	transformation(new Matrix{IdentityMatrix4x4})
{
	calculatePixelSize();
}

void Camera::calculatePixelSize() {
	auto halfView = tan(this->fieldOfView / 2.0f);
	auto aspect = static_cast<float>(this->hsize) / static_cast<float>(this->vsize);

	if (aspect > 1) {
		this->halfWidth = halfView;
		this->halfHeight = halfView / aspect;
	}
	else {
		this->halfWidth = halfView * aspect;
		this->halfHeight = halfView;
	}

	this->pixelSize = (this->halfWidth * 2.0f) / this->hsize;
}

ray rayForPixel(const Camera& c, float px, float py) {
	// the offset from the edge of the canvas to the pixel's center
	float xOffset = (px + 0.5f) * c.pixelSize;
	float yOffset = (py + 0.5f) * c.pixelSize;

	// the untransformed coordinates of the pixel in world space.
	// (remember that the camera looks towards -z, so +x is to the *left*.)
	float worldX = c.halfWidth - xOffset;
	float worldY = c.halfHeight - yOffset;

	// using the camera matrix, transform the canvas point and the origin,
	// and then compute the ray's direction vector.
	// (remember that the canvas is at z=-1.
	Matrix* inv = inverse(*c.transformation);
	auto pixel = *inv * point3 { worldX, worldY, -1.0f };
	auto origin = *inv * point3{ 0, 0, 0 };
	auto direction = normalize(pixel - origin);

	return ray{ origin, direction };
}

Canvas render(Camera camera, World world) {
	Canvas image{ camera.hsize, camera.vsize };

	for (int y = 0; y < camera.vsize; ++y) {
		for (int x = 0; x < camera.hsize; ++x) {
			ray r = rayForPixel(camera, static_cast<float>(x), static_cast<float>(y));
			Color colorToWrite = colorAt(world, r);
			image.writePixel(x, y, colorToWrite);
		}
	}

	return image;
}