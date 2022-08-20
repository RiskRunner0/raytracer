#include "PPMFileWriter.h"

void PPMFileWriter::WriteToPPMFile(const Canvas& canvas, std::string fileName) {
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

void PPMFileWriter::WriteHeader(std::ofstream& stream, int width, int height) const {
	stream << "P3" << std::endl;
	stream << width << " " << height << std::endl;
	stream << MAX_COLOR_VAL;
}

void PPMFileWriter::WriteColor(std::ofstream& stream, const Color& color) {
	int r = std::clamp(color.r() * 255, 0.0f, (float)MAX_COLOR_VAL);
	int g = std::clamp(color.g() * 255, 0.0f, (float)MAX_COLOR_VAL);
	int b = std::clamp(color.b() * 255, 0.0f, (float)MAX_COLOR_VAL);

	stream << r << " " << g << " " << b << " ";
}