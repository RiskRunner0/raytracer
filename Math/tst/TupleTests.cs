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
    }
}