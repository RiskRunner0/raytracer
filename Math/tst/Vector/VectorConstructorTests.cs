namespace Raytracer.Math.MathTests.Vector {
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class VectorConstructorTests {
        [TestMethod]
        public void VectorConstructionSetsXYandZ()
        {
            var v = new Math.Vector(1, 2, 3);

            Assert.AreEqual(1, v.x);
            Assert.AreEqual(2, v.y);
            Assert.AreEqual(3, v.z);
        }
    }
}