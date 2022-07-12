#include "Canvas.h"
#include "Color.h"

#include "gtest/gtest.h"

TEST(CanvasTests, AllColorsOfCanvasAreWhite)
{
	Canvas c{10, 20};

	EXPECT_EQ(10, c.width());
	EXPECT_EQ(20, c.height());

	Color white{ 0, 0, 0 };

	for (int h = 0; h < c.height(); ++h) {
		for (int w = 0; w < c.width(); ++w) {
			Color colorAtPos = c.pixelAt(w, h);
			EXPECT_EQ(white, colorAtPos);
		}
	}
}

TEST(CanvasTests, SetColor)
{
	Canvas c{ 10, 20 };
	Color red{ 1, 0, 0 };

	c.writePixel(2, 3, red);
	Color actual = c.pixelAt(2, 3);

	EXPECT_EQ(red, actual);
}