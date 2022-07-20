#pragma once

#include "tuple.h"

class Matrix {
public:
	Matrix(unsigned rows, unsigned cols);
	Matrix(const Matrix& m);
	~Matrix();

	unsigned Rows() const;
	unsigned Columns() const;

	Matrix transpose() const;
	float  Determinant() const;

	float&  operator() (unsigned row, unsigned col);		// set
	float   operator() (unsigned row, unsigned col) const;	// get
	bool    operator== (const Matrix& b) const;
	bool    operator!= (const Matrix& b) const;
	Matrix* operator* (const Matrix& b) const;
	tuple*  operator* (const tuple& b) const;

	static Matrix Get4x4Identity() {
		Matrix _4x4Identity{ 4, 4 };
		_4x4Identity(0, 0) = 1;
		_4x4Identity(1, 1) = 1;
		_4x4Identity(2, 2) = 1;
		_4x4Identity(3, 3) = 1;

		return _4x4Identity;
	}

private:
	unsigned _rows;
	unsigned _cols;
	float* _data;
};