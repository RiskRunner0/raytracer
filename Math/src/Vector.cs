namespace Raytracer.Math
{
    using System;

    public class Vector : Tuple
    {
        public Vector(float x, float y, float z)
            : this(x, y, z, 0)
        {
        }

        public Vector(float x, float y, float z, float w)
            : base(x, y, z, w)
        {
        }

        private double? magnitude;
        private Vector normalizedTuple;

        public double Magnitude
        {
            get
            {
                if (!magnitude.HasValue)
                {
                    this.magnitude = Math.Sqrt(x * x + y * y + z * z + w * w);
                }

                return this.magnitude.Value;
            }
        }

        public Vector NormalizedVector
        {
            get
            {
                if (normalizedTuple == null)
                {
                    normalizedTuple = new Vector(
                        this.x / (float)Magnitude,
                        this.y / (float)Magnitude,
                        this.z / (float)Magnitude,
                        this.w / (float)Magnitude
                    );
                }

                return normalizedTuple;
            }
        }

        public static Vector operator -(Vector a, Vector b)
        {
            return new Vector(
                a.x - b.x,
                a.y - b.y,
                a.z - b.z
            );
        }

        public float Dot(Vector v)
        {
            return this.x * v.x +
                this.y * v.y +
                this.z * v.z +
                this.w * v.w;
        }

        public Vector Cross(Vector v)
        {
            return new Vector(
                this.y * v.z - this.z * v.y,
                this.z * v.x - this.x * v.z,
                this.x * v.y - this.y * v.x
            );
        }
    }
}