namespace Raytracer.Math.Tests
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;

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
    }
}