#include "pch.h"
#include "CppUnitTest.h"
#include "../../Canvas.h"
#include "../../Color.h"
#include "../ToStringSpecializations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CanvasTests
{
	TEST_CLASS(CanvasTests)
	{
	public:
		TEST_METHOD(AllColorsOfCanvasAreWhite)
		{
			Canvas c{10, 20};

			Assert::AreEqual(10, c.width());
			Assert::AreEqual(20, c.height());

			Color white{ 0, 0, 0 };

			for (int h = 0; h < c.height(); ++h) {
				for (int w = 0; w < c.width(); ++w) {
					Color colorAtPos = c.pixelAt(w, h);
					Assert::AreEqual(white, colorAtPos);
				}
			}
		}

		TEST_METHOD(SetColor)
		{
			Canvas c{ 10, 20 };
			Color red{ 1, 0, 0 };

			c.writePixel(2, 3, red);
			Color actual = c.pixelAt(2, 3);

			Assert::AreEqual(red, actual);
		}
	};

	TEST_CLASS(PPMTests)
	{
	public:
		TEST_METHOD(WriteHeader)
		{}
	};
}
