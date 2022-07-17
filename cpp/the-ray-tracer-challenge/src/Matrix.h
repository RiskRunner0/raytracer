#pragma once

class Matrix {
public:
	Matrix(unsigned rows, unsigned cols);
	Matrix(const Matrix& m);
	~Matrix();

	unsigned Rows() const;
	unsigned Columns() const;

	float&  operator() (unsigned row, unsigned col);		// set
	float   operator() (unsigned row, unsigned col) const;	// get
	bool    operator== (const Matrix& b) const;
	bool    operator!= (const Matrix& b) const;
	Matrix* operator* (const Matrix& b) const;

private:
	unsigned _rows;
	unsigned _cols;
	float* _data;
};