#pragma once

#include "tuple.h"
#include "vec3.h"
#include "Math.h"
#include "point3.h"

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

	std::ostream& operator<<(std::ostream& os);

private:
	unsigned _rows;
	unsigned _cols;
	float* _data;
};

Matrix* submatrix(const Matrix& m, unsigned rowToRemove, unsigned colToRemove);

Matrix* inverse(const Matrix& m);

Matrix transpose(const Matrix& m);

static const float identityMatrixValues[] = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1,
};

static const Matrix IdentityMatrix4x4{ 4, 4, identityMatrixValues };

inline
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

inline
bool operator!= (const Matrix& a, const Matrix& b) {
	return !operator==(a, b);
}

inline
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

inline
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

inline
point3 operator* (const Matrix& m, const point3& p)
{
	return point3{ m * (tuple)p };
}

inline
vec3 operator* (const Matrix& m, const vec3& v)
{
	return vec3{ m * (tuple)v };
}

inline
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	for (unsigned r = 0; r < m.Rows(); ++r) {
		for (unsigned c = 0; c < m.Columns(); ++c) {
			os << m(r, c) << '\t';
		}

		os << std::endl;
	}

	return os;
}