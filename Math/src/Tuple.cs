namespace Raytracer.Math
{
    public class Tuple
    {
        public float x { get; set; }
        public float y { get; set; }
        public float z { get; set; }

        // Might need to rethink this, but this is how the book
        // writes these. Let's get it written then iterate.
        //
        // W == 1 - point
        // W == 0 - vector
        public float w { get; set; }

        public Tuple(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        public static Tuple operator+(Tuple a, Tuple b)
        {
            return new Tuple(
                a.x + b.x,
                a.y + b.y,
                a.z + b.z,
                a.w + b.w
            );
        }
    }
}
