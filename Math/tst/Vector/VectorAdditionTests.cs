namespace Raytracer.Math.MathTests.Vector
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class VectorAdditionTests
    {
        [TestMethod]
        public void AddingAVectorAndAPointResultsInAVector()
        {
            var p = new Math.Point(3, -2, 5);
            var v = new Math.Vector(-2, 3, 1);

            var result = v.Add(p);

            Assert.IsTrue(result is Math.Vector);
            Assert.AreEqual(1, result.x);
            Assert.AreEqual(1, result.y);
            Assert.AreEqual(6, result.z);
        }

        [TestMethod]
        public void AddingAVectorAndAPointReturnsWithCorrectMath()
        {
            var p = new Math.Point(3, -2, 5);
            var v = new Math.Vector(-2, 3, 1);

            var result = v.Add(p);

            Assert.AreEqual(1, result.x);
            Assert.AreEqual(1, result.y);
            Assert.AreEqual(6, result.z);
        }
    }
}