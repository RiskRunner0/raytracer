#include "Matrix.h"
#include <cstdarg>

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

Matrix* invert(const Matrix& m)
{
	float det = m.Determinant();
	if (det == 0) return NULL;
	
	Matrix* result = new Matrix{ m.Rows(), m.Columns() };

	// Calculate matrix of cofactors
	for (unsigned r = 0; r < result->Rows(); ++r)
	{
		for (unsigned c = 0; c < result->Columns(); ++c)
		{
			float cf = m.Cofactor(r, c);

			(*result)(c, r) = cf / det;
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

Matrix::Matrix(const unsigned rows, const unsigned cols) : Matrix(rows, cols, 0.0f) {
}

Matrix::Matrix(const Matrix& m) : _rows(m.Rows()), _cols(m.Columns()), _data(new float[_rows * _cols]) {
	for (unsigned r = 0; r < Rows(); ++r) {
		for (unsigned c = 0; c < Columns(); ++c) {
			operator()(r, c) = m(r, c);
		}
	}
}

Matrix::Matrix(unsigned rows, unsigned cols, const float data[]) : _rows(rows), _cols(cols), _data(new float[rows * cols])
{
	for (unsigned r = 0; r < _rows; ++r) {
		for (unsigned c = 0; c < _cols; ++c) {
			_data[_rows * r + c] = data[_rows * r + c];
		}
	}
}

Matrix::Matrix(unsigned rows, unsigned cols, float val) : _rows(rows), _cols(cols), _data(new float[_rows * cols])
{
	_data = new float[_rows * _cols];

	for (unsigned r = 0; r < _rows; ++r) {
		for (unsigned c = 0; c < _cols; ++c) {
			_data[_rows * r + c] = val;
		}
	}
}

Matrix::~Matrix() {
	// TODO: how do I do this??
	//delete[] _data;
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

float Matrix::Determinant() const {
	if (_rows == 2 && _cols == 2)
	{
		return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
	}

	float det = 0;
	
	for (unsigned i = 0; i < _cols; ++i)
	{
		det += (*this)(0, i) * Cofactor(0, i);
	}

	return det;
}

float Matrix::Minor(unsigned row, unsigned col) const {
	return submatrix(*this, row, col)->Determinant();
}

float Matrix::Cofactor(unsigned row, unsigned col) const {
	auto minor = this->Minor(row, col);

	// if row + col is odd, negate minor
	return (row + col) % 2 == 0 ? minor : -minor;
}

bool operator== (const Matrix& a, const Matrix& b) {
	if (b.Rows() != a.Rows() && b.Columns() != a.Columns()) return false;

	for (unsigned r = 0; r < a.Rows(); ++r) {
		for (unsigned c = 0; c < a.Columns(); ++c) {
			auto aVal = a(r, c);
			auto bVal = b(r, c);
			if (!floatEqual(aVal, bVal))
			{
				return false;
			}
		}
	}

	return true;
}

bool operator!= (const Matrix& a, const Matrix& b) {
	return !operator==(a, b);
}

Matrix operator* (const Matrix& a, const Matrix& b) {
	Matrix result = Matrix{ a.Rows(), b.Columns() };
	const unsigned length = result.Rows();

	for (unsigned r = 0; r < result.Rows(); ++r) {
		for (unsigned c = 0; c < result.Columns(); ++c) {
			float sum = 0.0f;

			for (unsigned i = 0; i < length; ++i) {
				sum += a(r, i) * b(i, c);
			}

			result(r, c) = sum;
		}
	}

	return result;
}

tuple operator* (const Matrix& m, const tuple& t) {
	Matrix bMat{ 4, 1 };
	bMat(0, 0) = t.x();
	bMat(1, 0) = t.y();
	bMat(2, 0) = t.z();
	bMat(3, 0) = t.w();

	Matrix res = m * bMat;

	auto x = res(0, 0);
	auto y = res(1, 0);
	auto z = res(2, 0);
	auto w = res(3, 0);

	return tuple{ x, y, z, w };
}

static const float identityMatrixValues[] = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1,
};
static const Matrix IdentityMatrix4x4{ 4, 4, identityMatrixValues };