namespace RayTracer.Drawing
{
    public class Color
    {
        public float red { get; set; }
        public float green { get; set; }
        public float blue { get; set; }

        public Color(float red, float green, float blue)
        {
            this.red = red;
            this.green = green;
            this.blue = blue;
        }

        public Color(double red, double green, double blue)
            : this((float)red, (float)green, (float)blue)
        { }

        public static Color operator +(Color a, Color b)
        {
            return new Color(
                a.red + b.red,
                a.green + b.green,
                a.blue + b.blue
            );
        }

        public static Color operator -(Color a, Color b)
        {
            return new Color(
                a.red - b.red,
                a.green - b.green,
                a.blue - b.blue
            );
        }

        public static Color operator *(Color a, int i)
        {
            return new Color(
                a.red * i,
                a.green * i,
                a.blue * i
            );
        }

        public static Color operator *(Color a, Color b)
        {
            return new Color(
                a.red * b.red,
                a.green * b.green,
                a.blue * b.blue
            );
        }
    }
}
