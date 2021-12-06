namespace RayTracer.Drawing
{
    public class Canvas
    {
        public int height {get; private set;}
        public int width {get; private set;}

        public Color[,] colors;

        public Canvas(int width, int height)
        {
            this.height = height;
            this.width = width;

            this.InitializeColors();
        }

        public void UpdatePixel(int x, int y, Color newColor)
        {
            this.colors[y,x] = newColor;
        }

        public Color GetPixel(int x, int y)
        {
            return this.colors[y,x];
        }

        private void InitializeColors() {
            this.colors = new Color[this.height, this.width];

            for (int i = 0; i < this.height; ++i)
            {
                for (int j = 0; j < this.width; ++j)
                {
                    this.colors[i,j] = new Color(0f, 0f, 0f);
                }
            }
        }
    }
}