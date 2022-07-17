#pragma once

#include "Canvas.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class PPMFileWriter {
public:
	void WriteToPPMFile(const Canvas& canvas, std::string fileName) {
		std::ofstream file;
		file.open(fileName);

		WriteHeader(file, canvas.width(), canvas.height());

		for (int i = 0; i < canvas.height(); ++i) {
			file << std::endl;

			for (int j = 0; j < canvas.width(); ++j) {
				WriteColor(file, canvas.pixelAt(j, i));
			}
		}

		file.close();
	}

private:
	static const int MAX_COLOR_VAL = 255;

	void WriteHeader(std::ofstream& stream, int width, int height) {
		stream << "P3" << std::endl;
		stream << width << " " << height << std::endl;
		stream << MAX_COLOR_VAL;
	}

	void WriteColor(std::ofstream& stream, const Color& color) {
		auto r = std::clamp(color.r(), 0.0f, (float)MAX_COLOR_VAL);
		auto g = std::clamp(color.g(), 0.0f, (float)MAX_COLOR_VAL);
		auto b = std::clamp(color.b(), 0.0f, (float)MAX_COLOR_VAL);

		stream << static_cast<int>(r) << " " << static_cast<int>(g) << " " << static_cast<int>(b) << " ";
	}
};