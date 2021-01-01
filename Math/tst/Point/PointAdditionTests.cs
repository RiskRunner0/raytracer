namespace Raytracer.Math.MathTests.Point
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class PointAdditionTests
    {
        [TestMethod]
        public void AddingAPointAndAVectorResultsInAVector()
        {
            var p = new Math.Point(3, -2, 5);
            var v = new Math.Vector(-2, 3, 1);

            var result = p.Add(v);

            Assert.IsTrue(result is Math.Vector);
        }

        [TestMethod]
        public void AddingAPointAndAVectorReturnsWithCorrectMath()
        {
            var p = new Math.Point(3, -2, 5);
            var v = new Math.Vector(-2, 3, 1);

            var result = p.Add(v);

            Assert.AreEqual(1, result.x);
            Assert.AreEqual(1, result.y);
            Assert.AreEqual(6, result.z);
        }

        [TestMethod]
        public void SubtractingTwoPointsResultsInAVector()
        {
            var p1 = new Math.Point(3, 2, 1);
            var p2 = new Math.Point(5, 6, 7);

            var result = p1.Subtract(p2);

            Assert.IsTrue(result is Math.Vector);
        }

        [TestMethod]
        public void SubtractingTwoPointsReturnsWithCorrectMath()
        {
            var p1 = new Math.Point(3, 2, 1);
            var p2 = new Math.Point(5, 6, 7);

            var result = p1.Subtract(p2);

            Assert.AreEqual(-2, result.x);
            Assert.AreEqual(-4, result.y);
            Assert.AreEqual(-6, result.z);
        }

        [TestMethod]
        public void SubtractingAVectorFromAPointResultsInOnlyAPoint()
        {
            var p = new Math.Point(3, 2, 1);
            var v = new Math.Vector(5, 6, 7);

            var result = p.Subtract(v);

            Assert.IsTrue(result is Math.Point);
            Assert.IsFalse(result is Math.Vector);
        }
    }
}