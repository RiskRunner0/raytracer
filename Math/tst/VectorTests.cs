namespace Raytracer.Math.Tests
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using System;

    [TestClass]
    public class VectorTests
    {
        [TestMethod]
        public void CreatingANewVectorSetsWTo0()
        {
            var p = new Vector(4, -4, 3);

            Assert.AreEqual(4, p.x);
            Assert.AreEqual(-4, p.y);
            Assert.AreEqual(3, p.z);
            Assert.AreEqual(0, p.w);
        }

        [TestMethod]
        public void SubtractingAVectorFromAVectorResultsInAVector()
        {
            var v1 = new Vector(3, 2, 1);
            var v2 = new Vector(5, 6, 7);

            var result = v1 - v2;
        }

        [TestMethod]
        public void SubtractingAVectorFromAVectorResultsInProperMath()
        {
            var v1 = new Vector(3, 2, 1);
            var v2 = new Vector(5, 6, 7);

            var result = v1 - v2;

            Assert.AreEqual(-2, result.x);
            Assert.AreEqual(-4, result.y);
            Assert.AreEqual(-6, result.z);
        }

        [TestMethod]
        public void MagnitudeCalculatesCorrectly()
        {
            var v = new Vector(1, 0, 0);

            Assert.AreEqual(1, v.Magnitude);

            v = new Vector(0, 1, 0);

            Assert.AreEqual(1, v.Magnitude);

            v = new Vector(0, 0, 1);

            Assert.AreEqual(1, v.Magnitude);

            v = new Vector(1, 2, 3);

            Assert.AreEqual(Math.Sqrt(14), v.Magnitude);

            v = new Vector(-1, -2, -3);

            Assert.AreEqual(Math.Sqrt(14), v.Magnitude);
        }

        [TestMethod]
        public void NormalizationChangesVectorIntoUnitVector()
        {
            var v = new Vector(4, 0, 0);
            var normalized = v.NormalizedVector;
            Assert.AreEqual(1, normalized.Magnitude);
        }

        [TestMethod]
        public void DotProductReturnsWithProperMath()
        {
            var a = new Vector(1, 2, 3);
            var b = new Vector(2, 3, 4);

            var result = a.Dot(b);

            Assert.AreEqual(20, result);
        }

        [TestMethod]
        public void CrossProductReturnsWithProperMath()
        {
            var a = new Vector(1, 2, 3);
            var b = new Vector(2, 3, 4);

            Vector result = a.Cross(b);

            Assert.AreEqual(-1, result.x);
            Assert.AreEqual(2, result.y);
            Assert.AreEqual(-1, result.z);

            result = b.Cross(a);

            Assert.AreEqual(1, result.x);
            Assert.AreEqual(-2, result.y);
            Assert.AreEqual(1, result.z);
        }
    }
}