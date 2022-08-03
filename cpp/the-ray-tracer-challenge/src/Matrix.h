#pragma once

#include "tuple.h"
#include "Math.h"

class Matrix {
public:
	Matrix(unsigned size);
	Matrix(unsigned rows, unsigned cols);
	Matrix(unsigned rows, unsigned cols, float val);
	Matrix(unsigned rows, unsigned cols, const float data[]);
	Matrix(const Matrix& m);
	~Matrix();

	unsigned Rows() const;
	unsigned Columns() const;

	float  Determinant() const;
	float  Minor(unsigned row, unsigned col) const;
	float  Cofactor(unsigned row, unsigned col) const;

	float&  operator() (unsigned row, unsigned col);		// set
	float   operator() (unsigned row, unsigned col) const;	// get

private:
	unsigned _rows;
	unsigned _cols;
	float* _data;
};