namespace Raytracer.Math
{
    public class Point
    {
        public float x { get; set; }
        public float y { get; set; }
        public float z { get; set; }

        public Point(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public static Vector operator+(Point p, Vector v) {
            return new Vector(
                v.x + p.x,
                v.y + p.y,
                v.z + p.z
            );
        }
    }
}
