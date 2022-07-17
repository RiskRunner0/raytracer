#include "Canvas.h"

Canvas::Canvas(int width, int height) : _width(width), _height(height), _vals{}
{
	_vals = new Color * [_height];

	for (int i = 0; i < _height; ++i) {
		_vals[i] = new Color[_width];
	}
}

int Canvas::width() const { return _width; }

int Canvas::height() const { return _height; }

Color Canvas::pixelAt(int x, int y) const { return _vals[y][x]; }

void Canvas::writePixel(int x, int y, Color c) { _vals[y][x] = c; }