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

        public Matrix(float[,] matrix)
        {
            this.internalMatrix = matrix;
            this.rows = matrix.GetLength(0);
            this.columns = matrix.GetLength(1);
        }

        public void Set(int row, int column, float value) => this.internalMatrix[row, column] = value;

        public float Get(int row, int column) => this.internalMatrix[row, column];

        public Matrix Transpose()
        {
            var m = new Matrix(this.rows, this.columns);

            for(int i = 0; i < m.rows; ++i)
            {
                for(int j = 0; j < m.columns; ++j)
                {
                    m.Set(i, j, this.Get(j, i));
                }
            }

            return m;
        }

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

        public static Matrix operator*(Matrix a, Matrix b)
        {
            var m = new Matrix(a.rows, b.columns);

            for (int i = 0; i < m.rows; i++)
            {
                for (int j = 0; j < m.columns; j++)
                {
                    m.Set(i, j, 0f);
                    
                    for (int k = 0; k < a.columns; k++)
                    {
                        var curVal = m.Get(i, j);
                        curVal += a.Get(i, k) * b.Get(k, j);
                        m.Set(i, j, curVal);
                    }
                }
            }

            return m;
        }

        public static Tuple operator*(Matrix m, Tuple t)
        {
            var tAsMatrix = new Matrix(new float[,] {
                { t.x },
                { t.y },
                { t.z },
                { t.w }
            });

            var result = m * tAsMatrix;

            return new Tuple(result.Get(0, 0), result.Get(1, 0), result.Get(2, 0), result.Get(3, 0));
        }

        public static Matrix IdentityMatrix => new Matrix(new float[,] {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        });
    }
}
