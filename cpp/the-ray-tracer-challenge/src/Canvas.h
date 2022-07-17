#pragma once

#include "Color.h"

class Canvas {
public:
	Canvas(int width, int height);

	int width() const;
	int height() const;
	Color pixelAt(int x, int y) const;
	void writePixel(int x, int y, Color c);

private:
	int _width;
	int _height;
	Color** _vals;
};
