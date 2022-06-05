#pragma once
#include "Color.h"

#ifndef CANVAS_H
#define CANVAS_H

class Canvas {
public:
	Canvas(int width, int height): _width(width), _height(height), _vals{}
	{
		_vals = new Color*[_height];

		for (int i = 0; i < _height; ++i) {
			_vals[i] = new Color[_width];
		}
	}

	int width() const { return _width; }
	int height() const { return _height; }
	Color pixelAt(int x, int y) const { return _vals[y][x]; }
	void writePixel(int x, int y, Color c) {
		_vals[y][x] = c;
	}

private:
	int _width;
	int _height;
	Color** _vals;
};

#endif // !CANVAS_H
