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

        [TestMethod]
        public void MatrixMathResultsInProperMath()
        {
            var a = new Matrix(new float[,] {
                { 1, 2, 3, 4 },
                { 5, 6, 7, 8 },
                { 9, 8, 7, 6 },
                { 5, 4, 3, 2 }
            });

            var b = new Matrix(new float[,] {
                { -2, 1, 2, 3 },
                { 3, 2, 1, -1 },
                { 4, 3, 6, 5 },
                { 1, 2, 7, 8 }
            });

            var expected = new Matrix(new float[,] {
                { 20, 22, 50, 48 },
                { 44, 54, 114, 108 },
                { 40, 58, 110, 102 },
                { 16, 26, 46, 42 }
            });

            Assert.IsTrue(Matrix.AreEqual(a * b, expected));
        }

        [TestMethod]
        public void MatrixMathMultiplicationWithVectorResultsInProperMath()
        {
            var a = new Matrix(new float[,] {
                { 1, 2, 3, 4 },
                { 2, 4, 4, 2 },
                { 8, 6, 4, 1 },
                { 0, 0, 0, 1 }
            });

            var t = new Tuple(1, 2, 3, 1);

            var result = a * t;

            var expected = new Tuple(18, 24, 33, 1);

            Assert.IsTrue(result.x == expected.x);
            Assert.IsTrue(result.y == expected.y);
            Assert.IsTrue(result.z == expected.z);
            Assert.IsTrue(result.w == expected.w);
        }

        [TestMethod]
        public void MultiplyingMatrixByIdentityMatrixGivesSameMatrix()
        {
            var a = new Matrix(new float[,] {
                { 0, 1, 2, 4 },
                { 1, 2, 4, 8 },
                { 2, 4, 8, 16 },
                { 4, 8, 16, 32 }
            });

            Assert.IsTrue(Matrix.AreEqual(a, a * Matrix.IdentityMatrix));
        }

        [TestMethod]
        public void TransposingMatrixResultsInCorrectMatrix()
        {
            var a = new Matrix(new float[,] {
                { 0, 9, 3, 0 },
                { 9, 8, 0, 8 },
                { 1, 8, 5, 3 },
                { 0, 0, 5, 8 }
            });

            var expected = new Matrix(new float[,] {
                { 0, 9, 1, 0 },
                { 9, 8, 8, 0 },
                { 3, 0, 5, 5 },
                { 0, 8, 3, 8 }
            });         

            var transposed = a.Transpose();
            Assert.IsTrue(Matrix.AreEqual(transposed, expected));   
        }
    }
}
