namespace RayTracer.Drawing.Tests
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class CanvasTests
    {
        [TestMethod]
        public void NewCanvasHasAllWhiteColors()
        {
            var canvas = new Canvas(10, 20);

            foreach(var h in canvas.colors)
            {
                Assert.AreEqual(0, h.red);
                Assert.AreEqual(0, h.green);
                Assert.AreEqual(0, h.blue);
            }
        }

        [TestMethod]
        public void WritingPixelsToACanvas()
        {
            var c = new Canvas(10, 20);
            var red = new Color(1f, 0f, 0f);
            c.UpdatePixel(2, 3, red);

            var updatedPixed = c.GetPixel(2, 3);

            Assert.AreEqual(1, updatedPixed.red);
            Assert.AreEqual(0, updatedPixed.green);
            Assert.AreEqual(0, updatedPixed.blue);
        }
    }
}