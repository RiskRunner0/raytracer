namespace RayTracer.TestCommon
{
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using System;

    [TestClass]
    public static class TestingUtilities
    {
        private static float EPSILON = 0.00001f;

        [TestMethod]
        public static bool AreWithinEpsilonTolerance(float a, float b)
        {
            return Math.Abs(a - b) < EPSILON;
        }
    }
}
