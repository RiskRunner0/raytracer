#include "Matrix.h"

Matrix::Matrix(const unsigned rows, const unsigned cols) : _rows(rows), _cols(cols) {
	_data = new float[_rows * _cols];

	for (unsigned r = 0; r < _rows; ++r) {
		for (unsigned c = 0; c < _cols; ++c) {
			_data[_rows * r + c] = 0.0;
		}
	}
}

Matrix::Matrix(const Matrix& m) : _rows(m.Rows()), _cols(m.Columns()), _data(new float[_rows * _cols]) {
	for (unsigned r = 0; r < Rows(); ++r) {
		for (unsigned c = 0; c < Columns(); ++c) {
			operator()(r, c) = m(r, c);
		}
	}
}

Matrix::~Matrix() {
	delete[] _data;
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

bool Matrix::operator== (const Matrix& b) const {
	if (b.Rows() != Columns() && b.Columns() != Columns()) return false;

	for (unsigned r = 0; r < Rows(); ++r) {
		for (unsigned c = 0; c < Columns(); ++c) {
			if (Matrix::operator()(r, c) != b(r, c)) return false;
		}
	}

	return true;
}

bool Matrix::operator!= (const Matrix& b) const {
	return !operator==(b);
}

Matrix* Matrix::operator* (const Matrix& b) const {
	Matrix* result = new Matrix{ Rows(), b.Columns() };
	const unsigned length = result->Rows();

	for (unsigned r = 0; r < result->Rows(); ++r) {
		for (unsigned c = 0; c < result->Columns(); ++c) {
			float sum = 0.0f;

			for (unsigned i = 0; i < length; ++i) {
				sum += operator()(r, i) * b(i, c);
			}

			(*result)(r, c) = sum;
		}
	}

	return result;
}