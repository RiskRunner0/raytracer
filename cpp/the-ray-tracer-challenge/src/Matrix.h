class Matrix
{
public:
    Matrix(int width, int height);
    ~Matrix();
    float& operator() (unsigned row, unsigned col);
    float  operator() (unsigned row, unsigned col) const;
    bool   operator== (const Matrix &b);
    bool   operator!= (const Matrix &b);

private:
    unsigned _rows, _cols;
    float& get(unsigned row, unsigned col);
    float  get(unsigned row, unsigned col) const;

    float* _data;
};

inline
float& Matrix::get(unsigned row, unsigned col) 
{
    return _data[_cols*row + col];
}

inline
float Matrix::get(unsigned row, unsigned col) const
{
    return _data[_cols*row + col];
}


inline
Matrix::Matrix(int rows, int cols)
{
    _rows = rows;
    _cols = cols;
    _data = new float[rows * cols];
}

inline
Matrix::~Matrix() 
{
    delete[] _data;
}

inline
float& Matrix::operator() (unsigned row, unsigned col)
{
    return get(row, col);
}

inline
float Matrix::operator() (unsigned row, unsigned col) const 
{
    return get(row, col);
}

inline
bool Matrix::operator==(const Matrix &b) {
    for(int i = 0; i < _rows; ++i) {
        for(int j =  0; j < _cols; ++j) {
            if(get(i, j) != b(i, j)) {
                return false;
            }
        }
    }

    return true;
}

inline
bool Matrix::operator!= (const Matrix &b) {
    return !this->operator==(b);
}