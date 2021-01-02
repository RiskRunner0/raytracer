namespace Raytracer.Math
{
    public class Point : Tuple
    {
        public Point(float x, float y, float z)
            : base(x, y, z, 1)
        {
        }

        public static Vector operator-(Point a, Point b)
        {
            return new Vector(
                a.x - b.x,
                a.y - b.y,
                a.z - b.z
            );
        }

        public static Point operator-(Point p, Vector v)
        {
            return new Point(
                p.x - v.x,
                p.y - v.y,
                p.z - v.z
            );
        }
    }
}