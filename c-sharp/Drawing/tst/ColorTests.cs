namespace RayTracer.Drawing.Tests
{
    using RayTracer.Drawing;
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using RayTracer.TestCommon;

    [TestClass]
    public class ColorTests
    {
        [TestMethod]
        public void AddingColorsResultsInProperNewColor()
        {
            var c1 = new Color(0.9f, .6f, 0.75f);
            var c2 = new Color(0.7f, 0.1f, 0.25f);

            var result = c1 + c2;


            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(1.6f, result.red));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.7f, result.green));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(1f, result.blue));
        }

        [TestMethod]
        public void SubtractingColorsResultsInProperNewColor()
        {
            var c1 = new Color(0.9f, .6f, 0.75f);
            var c2 = new Color(0.7f, 0.1f, 0.25f);

            var result = c1 - c2;


            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.2f, result.red));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.5f, result.green));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.5f, result.blue));
        }

        [TestMethod]
        public void MultiplyingColorByIntResultsInProperProperMath()
        {
            var c = new Color(0.2f, 0.3f, 0.4f);

            var result = c * 2;

            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.4f, result.red));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.6f, result.green));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.8f, result.blue));
        }

        [TestMethod]
        public void MultiplyingColorsTogetherResultsInBlendedColor()
        {
            var c1 = new Color(1f, 0.2f, 0.4f);
            var c2 = new Color(0.9f, 1f, 0.1f);

            var result = c1 * c2;

            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.9f, result.red));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.2f, result.green));
            Assert.IsTrue(TestingUtilities.AreWithinEpsilonTolerance(0.04f, result.blue));
        }
    }
}
