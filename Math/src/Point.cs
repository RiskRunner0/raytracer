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

        public Vector Add(Vector v)
        {
            return new Vector(
                v.x + this.x,
                v.y + this.y,
                v.z + this.z
            );
        }

        public Point Subtract(Point p)
        {
            float x = this.x - p.x;
            float y = this.y - p.y;
            float z = this.z - p.z;

            if(p is Vector) 
            {
                return new Point(x, y, z);
            }

            return new Vector(x, y, z);
        }
    }
}
