#include "../src/Matrix.h"
#include "../src/Matrix.cpp"
#include "../src/tuple.h"

#include "gtest/gtest.h"

TEST(MatrixTests, GetAndSet)
{
	Matrix m{ 4 };

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
	float aData[] = { 
		1,		2,		3,		4,
		5.5,	6.5,	7.5,	8.5,
		9,		10,		11,		12,
		13.5,	14.5,	15.5,	16.5
	};
	Matrix A{ 4, 4, aData };

	float bData[] = {
		1,		2,		3,		4,
		5.5,	6.5,	7.5,	8.5,
		9,		10,		11,		12,
		13.5,	14.5,	15.5,	16.5
	};
	Matrix B{ 4, 4, bData };
	
	EXPECT_TRUE(A == B);

	float cData[] = {
		1,		2,		3,		4,
		5.5,	6.5,	7.5,	8.5,
		9,		10,		11,		12,
		13.5,	14.5,	15.5,	17.5
	};

	Matrix C{ 4, 4, cData };

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

	Matrix C =  A * B;

	EXPECT_EQ(C.Rows(), A.Rows());
	EXPECT_EQ(C.Columns(), B.Columns());

	EXPECT_EQ(C(0, 0), 20);
	EXPECT_EQ(C(0, 1), 22);
	EXPECT_EQ(C(0, 2), 50);
	EXPECT_EQ(C(0, 3), 48);
	EXPECT_EQ(C(1, 0), 44);
	EXPECT_EQ(C(1, 1), 54);
	EXPECT_EQ(C(1, 2), 114);
	EXPECT_EQ(C(1, 3), 108);
	EXPECT_EQ(C(2, 0), 40);
	EXPECT_EQ(C(2, 1), 58);
	EXPECT_EQ(C(2, 2), 110);
	EXPECT_EQ(C(2, 3), 102);
	EXPECT_EQ(C(3, 0), 16);
	EXPECT_EQ(C(3, 1), 26);
	EXPECT_EQ(C(3, 2), 46);
	EXPECT_EQ(C(3, 3), 42);
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

	EXPECT_EQ(typeid(result), typeid(tuple));
	EXPECT_EQ(expected, result);
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

	auto result = A * IdentityMatrix4x4;

	EXPECT_EQ(typeid(result), typeid(Matrix));
	EXPECT_EQ(A, result);
}

TEST(MatrixTests, MultiplyingIdentityMatrixByTupleGivesTuple)
{
	tuple a{ 1, 2, 3, 4 };

	auto result = IdentityMatrix4x4 * a;

	EXPECT_EQ(typeid(result), typeid(tuple));
	EXPECT_EQ(a, result);
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

	EXPECT_EQ(transpose(A), expected);
}

TEST(MatrixTests, TransposingIdentityYieldsIdentity)
{
	EXPECT_EQ(transpose(IdentityMatrix4x4), IdentityMatrix4x4);
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

TEST(MatrixTests, Submatrix)
{
	Matrix a{ 3, 3 };

	a(0, 0) =  1;
	a(0, 1) =  5;
	a(0, 2) =  0;
	a(1, 0) = -3;
	a(1, 1) =  2;
	a(1, 2) =  7;
	a(2, 0) =  0;
	a(2, 1) =  6;
	a(2, 2) = -3;
	
	Matrix expected{ 2, 2 };

	expected(0, 0) = -3;
	expected(0, 1) =  2;
	expected(1, 0) =  0;
	expected(1, 1) =  6;

	Matrix* b = submatrix(a, 0, 2);

	EXPECT_EQ(expected, *b);

	// 4x4
	a = Matrix{ 4, 4 };
	a(0, 0) = -6;
	a(0, 1) =  1;
	a(0, 2) =  1;
	a(0, 3) =  6;
	a(1, 0) = -8;
	a(1, 1) =  5;
	a(1, 2) =  8;
	a(1, 3) =  6;
	a(2, 0) = -1;
	a(2, 1) =  0;
	a(2, 2) =  8;
	a(2, 3) =  2;
	a(3, 0) = -7;
	a(3, 1) =  1;
	a(3, 2) = -1;
	a(3, 3) =  1;

	expected = Matrix{ 3, 3 };
	expected(0, 0) = -6;
	expected(0, 1) =  1;
	expected(0, 2) =  6;
	expected(1, 0) = -8;
	expected(1, 1) =  8;
	expected(1, 2) =  6;
	expected(2, 0) = -7;
	expected(2, 1) = -1;
	expected(2, 2) =  1;

	b = submatrix(a, 2, 1);

	EXPECT_EQ(expected, *b);
}

TEST(MatrixTests, Minors)
{
	Matrix a{ 3, 3 };

	a(0, 0) = 3;
	a(0, 1) = 5;
	a(0, 2) = 0;
	a(1, 0) = 2;
	a(1, 1) = -1;
	a(1, 2) = -7;
	a(2, 0) = 6;
	a(2, 1) = -1;
	a(2, 2) = 5;

	Matrix* b = submatrix(a, 1, 0);
	EXPECT_EQ(b->Determinant(), 25);
	EXPECT_EQ(a.Minor(1, 0), 25);
}

TEST(MatrixTests, Cofactor)
{
	Matrix a{ 3, 3 };
	a(0, 0) = 3;
	a(0, 1) = 5;
	a(0, 2) = 0;
	a(1, 0) = 2;
	a(1, 1) = -1;
	a(1, 2) = -7;
	a(2, 0) = 6;
	a(2, 1) = -1;
	a(2, 2) = 5;

	EXPECT_EQ(a.Minor(0, 0), -12);
	EXPECT_EQ(a.Cofactor(0, 0), -12);
	EXPECT_EQ(a.Minor(1, 0), 25);
	EXPECT_EQ(a.Cofactor(1, 0), -25);
}

TEST(MatrixTests, Determinant3x3)
{
	Matrix a{ 3, 3 };
	a(0, 0) = 1;
	a(0, 1) = 2;
	a(0, 2) = 6;
	a(1, 0) = -5;
	a(1, 1) = 8;
	a(1, 2) = -4;
	a(2, 0) = 2;
	a(2, 1) = 6;
	a(2, 2) = 4;

	EXPECT_EQ(a.Cofactor(0, 0), 56);
	EXPECT_EQ(a.Cofactor(0, 1), 12);
	EXPECT_EQ(a.Cofactor(0, 2), -46);
	EXPECT_EQ(a.Determinant(), -196);
}

TEST(MatrixTests, Determinant4x4)
{
	Matrix a{ 4, 4 };
	a(0, 0) = -2;
	a(0, 1) = -8;
	a(0, 2) = 3;
	a(0, 3) = 5;
	a(1, 0) = -3;
	a(1, 1) = 1;
	a(1, 2) = 7;
	a(1, 3) = 3;
	a(2, 0) = 1;
	a(2, 1) = 2;
	a(2, 2) = -9;
	a(2, 3) = 6;
	a(3, 0) = -6;
	a(3, 1) = 7;
	a(3, 2) = 7;
	a(3, 3) = -9;

	EXPECT_EQ(a.Cofactor(0, 0), 690);
	EXPECT_EQ(a.Cofactor(0, 1), 447);
	EXPECT_EQ(a.Cofactor(0, 2), 210);
	EXPECT_EQ(a.Cofactor(0, 3), 51);
	EXPECT_EQ(a.Determinant(), -4071);
}

TEST(MatrixTests, CanInvert)
{
	Matrix a{ 4, 4 };
	a(0, 0) = 6;
	a(0, 1) = 4;
	a(0, 2) = 4;
	a(0, 3) = 4;
	a(1, 0) = 5;
	a(1, 1) = 5;
	a(1, 2) = 7;
	a(1, 3) = 6;
	a(2, 0) = 4;
	a(2, 1) = -9;
	a(2, 2) = 3;
	a(2, 3) = -7;
	a(3, 0) = 9;
	a(3, 1) = 1;
	a(3, 2) = 7;
	a(3, 3) = -6;

	EXPECT_TRUE(inverse(a) != NULL);
}

TEST(MatrixTests, CanNotInvert)
{
	Matrix a{ 4, 4 };
	a(0, 0) = -4;
	a(0, 1) = 2;
	a(0, 2) = -2;
	a(0, 3) = -3;
	a(1, 0) = 9;
	a(1, 1) = 6;
	a(1, 2) = 2;
	a(1, 3) = 6;
	a(2, 0) = 0;
	a(2, 1) = -5;
	a(2, 2) = 1;
	a(2, 3) = -5;
	a(3, 0) = 0;
	a(3, 1) = 0;
	a(3, 2) = 0;
	a(3, 3) = 0;

	EXPECT_TRUE(inverse(a) == NULL);
}

TEST(MatrixTests, Invert)
{
	Matrix a{ 4, 4 };
	a(0, 0) = -5;
	a(0, 1) = 2;
	a(0, 2) = 6;
	a(0, 3) = -8;
	a(1, 0) = 1;
	a(1, 1) = -5;
	a(1, 2) = 1;
	a(1, 3) = 8;
	a(2, 0) = 7;
	a(2, 1) = 7;
	a(2, 2) = -6;
	a(2, 3) = -7;
	a(3, 0) = 1;
	a(3, 1) = -3;
	a(3, 2) = 7;
	a(3, 3) = 4;

	Matrix* b = inverse(a);

	EXPECT_TRUE(b != NULL);
	EXPECT_EQ(a.Determinant(), 532);
	EXPECT_EQ(a.Cofactor(2, 3), -160);
	EXPECT_EQ((*b)(3, 2),  (float) -160 / (float) 532);
	EXPECT_EQ(a.Cofactor(3, 2), 105);
	EXPECT_EQ((*b)(2, 3), (float)105 / (float)532);

	Matrix expected{ 4, 4 };
	expected(0, 0) = 0.21805f;
	expected(0, 1) = 0.45113f;
	expected(0, 2) = 0.24060f;
	expected(0, 3) = -0.04511f;
	expected(1, 0) = -0.80827f;
	expected(1, 1) = -1.45677f;
	expected(1, 2) = -0.44361f;
	expected(1, 3) = 0.52068f;
	expected(2, 0) = -0.07895f;
	expected(2, 1) = -0.22368f;
	expected(2, 2) = -0.05263f;
	expected(2, 3) = 0.19737f;
	expected(3, 0) = -0.52256f;
	expected(3, 1) = -0.81391f;
	expected(3, 2) = -0.30075f;
	expected(3, 3) = 0.30639f;

	EXPECT_EQ(*b, expected);

	a(0, 0) = 8;
	a(0, 1) = -5;
	a(0, 2) = 9;
	a(0, 3) = 2;
	a(1, 0) = 7;
	a(1, 1) = 5;
	a(1, 2) = 6;
	a(1, 3) = 1;
	a(2, 0) = -6;
	a(2, 1) = 0;
	a(2, 2) = 9;
	a(2, 3) = 6;
	a(3, 0) = -3;
	a(3, 1) = 0;
	a(3, 2) = -9;
	a(3, 3) = -4;

	b = inverse(a);

	expected(0, 0) = -0.15385f;
	expected(0, 1) = -0.15385f;
	expected(0, 2) = -0.28205f;
	expected(0, 3) = -0.53846f;
	expected(1, 0) = -0.07692f;
	expected(1, 1) = 0.12308f;
	expected(1, 2) = 0.02564f;
	expected(1, 3) = 0.03077f;
	expected(2, 0) = 0.35897f;
	expected(2, 1) = 0.35897f;
	expected(2, 2) = 0.43590f;
	expected(2, 3) = 0.92308f;
	expected(3, 0) = -0.69231f;
	expected(3, 1) = -0.69231f;
	expected(3, 2) = -0.76923f;
	expected(3, 3) = -1.92308f;

	EXPECT_EQ(*b, expected);

	a(0, 0) = 9;
	a(0, 1) = 3;
	a(0, 2) = 0;
	a(0, 3) = 9;
	a(1, 0) = -5;
	a(1, 1) = -2;
	a(1, 2) = -6;
	a(1, 3) = -3;
	a(2, 0) = -4;
	a(2, 1) = 9;
	a(2, 2) = 6;
	a(2, 3) = 4;
	a(3, 0) = -7;
	a(3, 1) = 6;
	a(3, 2) = 6;
	a(3, 3) = 2;

	b = inverse(a);

	expected(0, 0) = -0.04074f;
	expected(0, 1) = -0.07778f;
	expected(0, 2) = 0.14444f;
	expected(0, 3) = -0.22222f;
	expected(1, 0) = -0.07778f;
	expected(1, 1) = 0.03333f;
	expected(1, 2) = 0.36667f;
	expected(1, 3) = -0.33333f;
	expected(2, 0) = -0.02901f;
	expected(2, 1) = -0.14630f;
	expected(2, 2) = -0.10926f;
	expected(2, 3) = 0.12963f;
	expected(3, 0) = 0.17778f;
	expected(3, 1) = 0.06667f;
	expected(3, 2) = -0.26667f;
	expected(3, 3) = 0.33333f;

	EXPECT_EQ(*b, expected);
}

TEST(MatrixTests, MultiplicativeProperty)
{
	Matrix a{ 4, 4 };
	a(0, 0) = 3;
	a(0, 1) = -9;
	a(0, 2) = 7;
	a(0, 3) = 3;
	a(1, 0) = 3;
	a(1, 1) = -8;
	a(1, 2) = 2;
	a(1, 3) = -9;
	a(2, 0) = -4;
	a(2, 1) = 4;
	a(2, 2) = 4;
	a(2, 3) = 1;
	a(3, 0) = -6;
	a(3, 1) = 5;
	a(3, 2) = -1;
	a(3, 3) = 1;

	Matrix b{ 4, 4 };
	b(0, 0) = 8;
	b(0, 1) = 2;
	b(0, 2) = 2;
	b(0, 3) = 2;
	b(1, 0) = 3;
	b(1, 1) = -1;
	b(1, 2) = 7;
	b(1, 3) = 0;
	b(2, 0) = 7;
	b(2, 1) = 0;
	b(2, 2) = 5;
	b(2, 3) = 4;
	b(3, 0) = 6;
	b(3, 1) = -2;
	b(3, 2) = 0;
	b(3, 3) = 5;

	Matrix c = a * b;

	Matrix result = c * (*inverse(b));
	EXPECT_EQ(result, a);
}