namespace Raytracer.Math
{
    public class Vector : Tuple
    {
        public Vector(float x, float y, float z)
            : base(x, y, z, 0)
        {
        }

        public static Vector operator-(Vector a, Vector b)
        {
            return new Vector(
                a.x - b.x,
                a.y - b.y,
                a.z - b.z
            );
        }
    }
}