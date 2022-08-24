#include "Translation.h"

Matrix translation(float x, float y, float z)
{
	float values[] = {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1,
	};

	return Matrix{ 4, 4, values };
}

Matrix scaling(float x, float y, float z)
{
	float values[] = {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1,
	};

	return Matrix{ 4, 4, values };
}

Matrix rotation_x(float radians)
{
	float sinVal = (float)sin(radians);
	float cosVal = (float)cos(radians);

	float values[] = {
		1,	0,		0,			0,
		0,	cosVal,	-sinVal,	0,
		0,	sinVal,	cosVal,		0,
		0,	0,		0,			1,				1
	};

	return Matrix{ 4, 4, values };
}

Matrix rotation_y(float radians)
{
	float sinVal = (float)sin(radians);
	float cosVal = (float)cos(radians);

	float values[] = {
		cosVal,		0,	sinVal,	0,
		0,			1,	0,		0,
		-sinVal,	0,	cosVal, 0,
		0,			0,	0,		1,
	};

	return Matrix{ 4, 4, values };
}

Matrix rotation_z(float radians)
{
	float sinVal = (float)sin(radians);
	float cosVal = (float)cos(radians);

	float values[] = {
		cosVal, -sinVal,	0, 0,
		sinVal, cosVal,		0, 0,
		0,		0,			1, 0,
		0,		0,			0, 1,
	};

	return Matrix{ 4, 4, values };
}

Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
	float values[] = {
		1.0f,	xy,		xz,		0.0f,
		yx,		1.0f,	yz,		0.0f,
		zx,		zy,		1,		0,
		0,		0,		0,		1,
	};
	return Matrix{4, 4, values};
}

Matrix viewTransformation(vec3 from, vec3 to, vec3 up) {
	auto forward = normalize(to - from);
	auto upn = normalize(up);
	auto left = cross(forward, upn);
	auto trueUp = cross(left, forward);

	float values[] = {
		left.x(),		left.y(),		left.z(),		0,
		trueUp.x(),		trueUp.y(),		trueUp.z(),		0,
		-forward.x(),	-forward.y(),	-forward.z(),	0,
		0,				0,				0,				1,
	};

	Matrix orientation{ 4, 4, values };

	return orientation * translation(-from.x(), -from.y(), -from.z());
}