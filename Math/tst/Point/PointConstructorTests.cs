using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Raytracer.Math.MathTests.Point
{
    [TestClass]
    public class PointConstructorTests
    {
        [TestMethod]
        public void PointConstructorSetsXYandZ()
        {
            var p = new Math.Point(1, 2, 3);

            Assert.AreEqual(1, p.x);
            Assert.AreEqual(2, p.y);
            Assert.AreEqual(3, p.z);
        }
    }
}
