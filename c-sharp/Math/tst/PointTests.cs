namespace Raytracer.Math.Tests
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class PointTests
    {
        [TestMethod]
        public void CreatingANewPointSetsWTo1()
        {
            var p = new Point(4, -4, 3);

            Assert.AreEqual(4, p.x);
            Assert.AreEqual(-4, p.y);
            Assert.AreEqual(3, p.z);
            Assert.AreEqual(1, p.w);
        }

        [TestMethod]
        public void SubtractingTwoPointsResultsInAVector()
        {
            var p1 = new Point(3, 2, 1);
            var p2 = new Point(5, 6, 7);

            var result = p1 - p2;

            Assert.IsTrue(result is Vector);
        }

        [TestMethod]
        public void SubtractingTwoPointsResultsInProperMath()
        {
            var p1 = new Point(3, 2, 1);
            var p2 = new Point(5, 6, 7);

            var result = p1 - p2;

            Assert.AreEqual(-2, result.x);
            Assert.AreEqual(-4, result.y);
            Assert.AreEqual(-6, result.z);
        }

        [TestMethod]
        public void SubtractingAVectorFromAPointResultsInAPoint()
        {
            var p = new Point(3, 2, 1);
            var v = new Vector(5, 6, 7);

            var result = p - v;

            Assert.IsTrue(result is Point);
        }

        [TestMethod]
        public void SubtractingAVectorFromAPointResultsInProperMath()
        {
            var p = new Point(3, 2, 1);
            var v = new Vector(5, 6, 7);

            var result = p - v;

            Assert.AreEqual(-2, result.x);
            Assert.AreEqual(-4, result.y);
            Assert.AreEqual(-6, result.z);
        }
    }
}