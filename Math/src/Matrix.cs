namespace Raytracer.Math
{
    public class Matrix
    {
        private float[,] internalMatrix;

        private readonly int rows;
        private readonly int columns;

        public Matrix(int rows, int columns)
        {
            this.internalMatrix = new float[rows, columns];
            this.rows = rows;
            this.columns = columns;
        }

        public Matrix(int squareSize)
            :this(squareSize, squareSize)
        { }

        public void Set(int row, int column, float value) => this.internalMatrix[row, column] = value;

        public float Get(int row, int column) => this.internalMatrix[row, column];

        public static bool AreEqual(Matrix a, Matrix b)
        {
            if (a.rows != b.rows || a.columns != b.columns) return false;

            for(int row = 0; row < a.rows; ++row)
            {
                for(int column = 0; column < a.columns; ++column)
                {
                    if(a.Get(row, column) != b.Get(row, column))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }
}
