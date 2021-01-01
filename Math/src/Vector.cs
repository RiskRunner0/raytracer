namespace Raytracer.Math
{
    using System;

    public class Vector : Point
    {
        public float w { get; set; }

        public Vector(float x, float y, float z)
            : base(x, y, z) { }
    }
}
