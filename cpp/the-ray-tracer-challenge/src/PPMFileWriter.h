#pragma once

#include "Canvas.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class PPMFileWriter {
public:
	void WriteToPPMFile(const Canvas& canvas, std::string fileName);

private:
	static const int MAX_COLOR_VAL = 255;

	void WriteHeader(std::ofstream& stream, int width, int height) const;

	void WriteColor(std::ofstream& stream, const Color& color);
};