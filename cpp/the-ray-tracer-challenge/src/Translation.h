#pragma once

#include "Matrix.h"
#include "point3.h"

Matrix translation(float x, float y, float z);

Matrix scaling(float x, float y, float z);

Matrix rotation_x(float ratians);

Matrix rotation_y(float ratians);

Matrix rotation_z(float ratians);

Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy);