using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Raytracer.Math.Tests
{
    [TestClass]
    public class MatrixTests
    {
        [TestMethod]
        public void MatriciesAreTheSame()
        {
            var a = new Matrix(2);
            var b = new Matrix(2);

            a.Set(0, 0, 1);
            a.Set(0, 1, 2);
            a.Set(1, 0, 3);
            a.Set(1, 1, 4);

            b.Set(0, 0, 1);
            b.Set(0, 1, 2);
            b.Set(1, 0, 3);
            b.Set(1, 1, 4);

            Assert.IsTrue(Matrix.AreEqual(a, b));
        }

        [TestMethod]
        public void MatriciesThatAreNotSimilarDimensionsAreNotEqual()
        {
            var a = new Matrix(2);
            var b = new Matrix(3);

            Assert.IsFalse(Matrix.AreEqual(a, b));
        }

        [TestMethod]
        public void MatriciesAreNotEqual()
        {
            var a = new Matrix(2);
            var b = new Matrix(2);

            a.Set(0, 0, 1);
            a.Set(0, 1, 2);
            a.Set(1, 0, 3);
            a.Set(1, 1, 4);

            b.Set(0, 0, 2);
            b.Set(0, 1, 3);
            b.Set(1, 0, 4);
            b.Set(1, 1, 5);

            Assert.IsFalse(Matrix.AreEqual(a, b));
        }
    }
}
