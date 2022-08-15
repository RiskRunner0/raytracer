#include "Matrix.h"

Matrix* submatrix(const Matrix& m, unsigned rowToRemove, unsigned colToRemove) {
	Matrix* result = new Matrix{ m.Rows() - 1, m.Columns() - 1 };

	unsigned wRow = 0;
	unsigned wCol = 0;

	for (unsigned rRow = 0; rRow < m.Rows(); ++rRow)
	{
		if (rRow == rowToRemove) continue;
		wCol = 0;

		for (unsigned rCol = 0; rCol < m.Columns(); ++rCol)
		{
			if (rCol == colToRemove) continue;

			auto toWrite = m(rRow, rCol);
			(*result)(wRow, wCol) = toWrite;

			++wCol;
		}

		++wRow;
	}

	return result;
}

Matrix* inverse(const Matrix& m)
{
	Matrix copy{ m };
	float determinant = copy.Determinant();
	if (determinant == 0) return NULL;
	
	Matrix* result = new Matrix{ m.Rows(), m.Columns() };

	// Calculate matrix of cofactors
	for (unsigned r = 0; r < result->Rows(); ++r)
	{
		for (unsigned c = 0; c < result->Columns(); ++c)
		{
			float cf = m.Cofactor(r, c);

			(*result)(c, r) = cf / determinant;
		}
	}

	return result;
}

Matrix transpose(const Matrix& m) {
	Matrix copied{ m.Columns(), m.Rows() };

	for (unsigned r = 0; r < m.Rows(); ++r)
	{
		for (unsigned c = 0; c < m.Columns(); ++c) {
			copied(c, r) = m(r, c);
		}
	}

	return copied;
}

Matrix::Matrix(unsigned size) : Matrix(size, size)
{
}

Matrix::Matrix(const unsigned rows, const unsigned cols) : _rows(rows), _cols(cols), _data(rows* cols) {
}

Matrix::Matrix(const Matrix& m) : _rows(m.Rows()), _cols(m.Columns()), _data(m.Rows() * m.Columns()) {
	for (unsigned r = 0; r < Rows(); ++r) {
		for (unsigned c = 0; c < Columns(); ++c) {
			operator()(r, c) = m(r, c);
		}
	}
}

Matrix::Matrix(unsigned rows, unsigned cols, const float data[]) : _rows(rows), _cols(cols), _data(rows * cols)
{
	for (unsigned r = 0; r < _rows; ++r) {
		for (unsigned c = 0; c < _cols; ++c) {
			auto read = data[_rows * r + c];
			_data[_cols * r + c] = read;
		}
	}
}

Matrix::Matrix(unsigned rows, unsigned cols, float val) : _rows(rows), _cols(cols), _data(rows* cols)
{
	for (unsigned r = 0; r < _rows; ++r) {
		for (unsigned c = 0; c < _cols; ++c) {
			_data[_cols * r + c] = val;
		}
	}
}

Matrix::~Matrix() {
	// TODO: how do I do this??
}

unsigned Matrix::Rows() const {
	return _rows;
}

unsigned Matrix::Columns() const {
	return _cols;
}

float& Matrix::operator() (unsigned row, unsigned col) {
	return _data[row * _cols + col];
}

float Matrix::operator() (unsigned row, unsigned col) const {
	return _data[row * _cols + col];
}

float Matrix::Determinant() {
	if (isDetCached) return this->det;

	if (_rows == 2 && _cols == 2)
	{
		return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
	}

	float det = 0;
	
	for (unsigned i = 0; i < _cols; ++i)
	{
		det += (*this)(0, i) * Cofactor(0, i);
	}

	this->det = det;
	this->isDetCached = true;

	return det;
}

float Matrix::Minor(unsigned row, unsigned col) const {
	Matrix* sub = submatrix(*this, row, col);
	float det = sub->Determinant();
	delete sub;
	return det;
}

float Matrix::Cofactor(unsigned row, unsigned col) const {
	auto minor = this->Minor(row, col);

	// if row + col is odd, negate minor
	return (row + col) % 2 == 0 ? minor : -minor;
}