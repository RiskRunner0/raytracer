namespace Raytracer.MathTests {
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using Raytracer.Math;

    [TestClass]
    public class VectorTests {
        [TestMethod]
        public void VectorConstructionSetsXYandZ()
        {
            var v = new Vector(1, 2, 3);

            Assert.AreEqual(1, v.x);
            Assert.AreEqual(2, v.y);
            Assert.AreEqual(3, v.z);
        }
    }
}