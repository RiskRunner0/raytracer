namespace Raytracer.Math.Tests
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class TupleTests
    {
        [TestMethod]
        public void AddingTwoTuplesResultsInProperMath()
        {
            var a1 = new Tuple(3, -2, 5, 1);
            var a2 = new Tuple(-2, 3, 1, 0);

            var result = a1 + a2;

            Assert.AreEqual(1, result.x);
            Assert.AreEqual(1, result.y);
            Assert.AreEqual(6, result.z);
            Assert.AreEqual(1, result.w);
        }

        [TestMethod]
        public void NegatingATupleResultsInProperMath()
        {
            var a = new Tuple(1, -2, 3, -4);

            var result = -a;

            Assert.AreEqual(-1, result.x);
            Assert.AreEqual(2, result.y);
            Assert.AreEqual(-3, result.z);
            Assert.AreEqual(4, result.w);
        }

        [TestMethod]
        public void MultiplyingATupleByAScalarNumberResultsInProperMath()
        {
            var a = new Tuple(1, -2, 3, -4);

            var result = a * 3.5;

            Assert.AreEqual(3.5, result.x);
            Assert.AreEqual(-7, result.y);
            Assert.AreEqual(10.5, result.z);
            Assert.AreEqual(-14, result.w);
        }

        [TestMethod]
        public void DividingATupleByAScalarNumberResultsInProperMath()
        {
            var a = new Tuple(1, -2, 3, -4);

            var result = a / 2;

            Assert.AreEqual(0.5, result.x);
            Assert.AreEqual(-1, result.y);
            Assert.AreEqual(1.5, result.z);
            Assert.AreEqual(-2, result.w);            
        } 
    }
}