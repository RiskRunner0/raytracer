#include "../src/Matrix.h"
#include "../src/Matrix.cpp"
#include "../src/tuple.h"

#include "gtest/gtest.h"

TEST(MatrixTests, GetAndSet)
{
	Matrix m{ 4, 4 };

	m(0, 0) = 1;
	m(0, 1) = 2;
	m(0, 2) = 3;
	m(0, 3) = 4;
	m(1, 0) = 5.5;
	m(1, 1) = 6.5;
	m(1, 2) = 7.5;
	m(1, 3) = 8.5;
	m(2, 0) = 9;
	m(2, 1) = 10;
	m(2, 2) = 11;
	m(2, 3) = 12;
	m(3, 0) = 13.5;
	m(3, 1) = 14.5;
	m(3, 2) = 15.5;
	m(3, 3) = 16.5;

	EXPECT_EQ(m(0, 0), 1);
	EXPECT_EQ(m(0, 1), 2);
	EXPECT_EQ(m(0, 2), 3);
	EXPECT_EQ(m(0, 3), 4);
	EXPECT_EQ(m(1, 0), 5.5);
	EXPECT_EQ(m(1, 1), 6.5);
	EXPECT_EQ(m(1, 2), 7.5);
	EXPECT_EQ(m(1, 3), 8.5);
	EXPECT_EQ(m(2, 0), 9);
	EXPECT_EQ(m(2, 1), 10);
	EXPECT_EQ(m(2, 2), 11);
	EXPECT_EQ(m(2, 3), 12);
	EXPECT_EQ(m(3, 0), 13.5);
	EXPECT_EQ(m(3, 1), 14.5);
	EXPECT_EQ(m(3, 2), 15.5);
	EXPECT_EQ(m(3, 3), 16.5);
}

TEST(MatrixTests, Comparisons)
{
	Matrix A{ 4, 4 };

	A(0, 0) = 1;
	A(0, 1) = 2;
	A(0, 2) = 3;
	A(0, 3) = 4;
	A(1, 0) = 5.5;
	A(1, 1) = 6.5;
	A(1, 2) = 7.5;
	A(1, 3) = 8.5;
	A(2, 0) = 9;
	A(2, 1) = 10;
	A(2, 2) = 11;
	A(2, 3) = 12;
	A(3, 0) = 13.5;
	A(3, 1) = 14.5;
	A(3, 2) = 15.5;
	A(3, 3) = 16.5;

	Matrix B{ 4, 4 };

	B(0, 0) = 1;
	B(0, 1) = 2;
	B(0, 2) = 3;
	B(0, 3) = 4;
	B(1, 0) = 5.5;
	B(1, 1) = 6.5;
	B(1, 2) = 7.5;
	B(1, 3) = 8.5;
	B(2, 0) = 9;
	B(2, 1) = 10;
	B(2, 2) = 11;
	B(2, 3) = 12;
	B(3, 0) = 13.5;
	B(3, 1) = 14.5;
	B(3, 2) = 15.5;
	B(3, 3) = 16.5;
	
	EXPECT_TRUE(A == B);

	Matrix C{ 4, 4 };

	C(0, 0) = 1;
	C(0, 1) = 2;
	C(0, 2) = 3;
	C(0, 3) = 4;
	C(1, 0) = 5.5;
	C(1, 1) = 6.5;
	C(1, 2) = 7.5;
	C(1, 3) = 8.5;
	C(2, 0) = 9;
	C(2, 1) = 10;
	C(2, 2) = 11;
	C(2, 3) = 12;
	C(3, 0) = 13.5;
	C(3, 1) = 14.5;
	C(3, 2) = 15.5;
	C(3, 3) = 17.5;

	EXPECT_TRUE(B != C);
}

TEST(MatrixTests, Multiplication) {
	Matrix A{ 4, 4 };

	A(0, 0) = 1;
	A(0, 1) = 2;
	A(0, 2) = 3;
	A(0, 3) = 4;
	A(1, 0) = 5;
	A(1, 1) = 6;
	A(1, 2) = 7;
	A(1, 3) = 8;
	A(2, 0) = 9;
	A(2, 1) = 8;
	A(2, 2) = 7;
	A(2, 3) = 6;
	A(3, 0) = 5;
	A(3, 1) = 4;
	A(3, 2) = 3;
	A(3, 3) = 2;

	Matrix B{ 4, 4 };

	B(0, 0) = -2;
	B(0, 1) =  1;
	B(0, 2) =  2;
	B(0, 3) =  3;
	B(1, 0) =  3;
	B(1, 1) =  2;
	B(1, 2) =  1;
	B(1, 3) = -1;
	B(2, 0) =  4;
	B(2, 1) =  3;
	B(2, 2) =  6;
	B(2, 3) =  5;
	B(3, 0) =  1;
	B(3, 1) =  2;
	B(3, 2) =  7;
	B(3, 3) =  8;

	Matrix* C =  A * B;

	EXPECT_EQ(C->Rows(), A.Rows());
	EXPECT_EQ(C->Columns(), B.Columns());

	EXPECT_EQ((*C)(0, 0), 20);
	EXPECT_EQ((*C)(0, 1), 22);
	EXPECT_EQ((*C)(0, 2), 50);
	EXPECT_EQ((*C)(0, 3), 48);
	EXPECT_EQ((*C)(1, 0), 44);
	EXPECT_EQ((*C)(1, 1), 54);
	EXPECT_EQ((*C)(1, 2), 114);
	EXPECT_EQ((*C)(1, 3), 108);
	EXPECT_EQ((*C)(2, 0), 40);
	EXPECT_EQ((*C)(2, 1), 58);
	EXPECT_EQ((*C)(2, 2), 110);
	EXPECT_EQ((*C)(2, 3), 102);
	EXPECT_EQ((*C)(3, 0), 16);
	EXPECT_EQ((*C)(3, 1), 26);
	EXPECT_EQ((*C)(3, 2), 46);
	EXPECT_EQ((*C)(3, 3), 42);
}

TEST(MatrixTests, MultiplyByTuple)
{
	Matrix A{ 4, 4 };

	A(0, 0) = 1;
	A(0, 1) = 2;
	A(0, 2) = 3;
	A(0, 3) = 4;
	A(1, 0) = 2;
	A(1, 1) = 4;
	A(1, 2) = 4;
	A(1, 3) = 2;
	A(2, 0) = 8;
	A(2, 1) = 6;
	A(2, 2) = 4;
	A(2, 3) = 1;
	A(3, 0) = 0;
	A(3, 1) = 0;
	A(3, 2) = 0;
	A(3, 3) = 1;

	tuple b{ 1, 2, 3, 1 };

	tuple expected{ 18, 24, 33, 1 };

	auto result = A * b;

	EXPECT_EQ(typeid(result), typeid(tuple*));
	EXPECT_EQ(expected, *result);
}

TEST(MatrixTests, MultiplyingByIdentityGivesSameMatrix)
{
	Matrix A{ 4, 4 };

	A(0, 0) = 0;
	A(0, 1) = 1;
	A(0, 2) = 2;
	A(0, 3) = 4;
	A(1, 0) = 1;
	A(1, 1) = 2;
	A(1, 2) = 4;
	A(1, 3) = 8;
	A(2, 0) = 2;
	A(2, 1) = 4;
	A(2, 2) = 8;
	A(2, 3) = 16;
	A(3, 0) = 4;
	A(3, 1) = 8;
	A(3, 2) = 16;
	A(3, 3) = 32;

	auto result = A * Matrix::Get4x4Identity();

	EXPECT_EQ(typeid(result), typeid(Matrix*));
	EXPECT_EQ(A, *result);
}

TEST(MatrixTests, MultiplyingIdentityMatrixByTupleGivesTuple)
{
	tuple a{ 1, 2, 3, 4 };

	auto result = Matrix::Get4x4Identity() * a;

	EXPECT_EQ(typeid(result), typeid(tuple*));
	EXPECT_EQ(a, *result);
}

TEST(MatrixTests, Transpose)
{
	Matrix A{ 4, 4 };

	A(0, 0) = 0;
	A(0, 1) = 9;
	A(0, 2) = 3;
	A(0, 3) = 0;
	A(1, 0) = 9;
	A(1, 1) = 8;
	A(1, 2) = 0;
	A(1, 3) = 8;
	A(2, 0) = 1;
	A(2, 1) = 8;
	A(2, 2) = 5;
	A(2, 3) = 3;
	A(3, 0) = 0;
	A(3, 1) = 0;
	A(3, 2) = 5;
	A(3, 3) = 8;

	Matrix expected{ 4, 4 };

	expected(0, 0) = 0;
	expected(0, 1) = 9;
	expected(0, 2) = 1;
	expected(0, 3) = 0;
	expected(1, 0) = 9;
	expected(1, 1) = 8;
	expected(1, 2) = 8;
	expected(1, 3) = 0;
	expected(2, 0) = 3;
	expected(2, 1) = 0;
	expected(2, 2) = 5;
	expected(2, 3) = 5;
	expected(3, 0) = 0;
	expected(3, 1) = 8;
	expected(3, 2) = 3;
	expected(3, 3) = 8;

	auto result = A.transpose();

	EXPECT_EQ(result, expected);
}

TEST(MatrixTests, TransposingIdentityYieldsIdentity)
{
	EXPECT_EQ(Matrix::Get4x4Identity().transpose(), Matrix::Get4x4Identity());
}

TEST(MatrixTests, Determinant)
{
	Matrix a{ 2, 2 };

	a(0, 0) =  1;
	a(0, 1) =  5;
	a(1, 0) = -3;
	a(1, 1) = 2;

	auto det = a.Determinant();

	EXPECT_EQ(det, 17);
}