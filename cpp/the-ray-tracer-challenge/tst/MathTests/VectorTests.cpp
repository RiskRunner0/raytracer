#include "pch.h"
#include "CppUnitTest.h"
#include "../../vec3.h"
#include "../../Math.h"
#include "ToStringSpecializations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
	TEST_CLASS(MathTests)
	{
	public:
		
		TEST_METHOD(SubtractingPointsCreatesVector)
		{
			point3 p1{ 3, 2, 1 };
			point3 p2{ 5, 6, 7 };

			vec3 expected{ -2, -4, -6 };

			auto result = p1 - p2;
			Assert::AreEqual(expected, p1 - p2);
		}

		TEST_METHOD(SubtractingVectorFromPointCreatesPoint)
		{
			point3 p{ 3, 2, 1 };
			vec3 v{ 5, 6, 7 };

			point3 expected{ -2, -4, -6 };
			Assert::AreEqual(expected, p - v);
		}

		TEST_METHOD(Subtracting2VectorsCreatesVector)
		{
			vec3 v1{ 3, 2, 1 };
			vec3 v2{ 5, 6, 7 };

			vec3 expected{ -2, -4, -6 };
			Assert::AreEqual(expected, v1 - v2);
		}

		TEST_METHOD(SubtractingVectorFromZeroVectorNegatesVector)
		{
			vec3 zero{ 0, 0, 0 };
			vec3 v{ 1, -2, 3 };

			vec3 expected{ -1, 2, -3 };
			Assert::AreEqual(expected, zero - v);
		}

		TEST_METHOD(NegatingVector)
		{
			vec3 a{ 1, -2, 3 };
			vec3 expected{ -1, 2, -3 };

			Assert::AreEqual(expected, -a);
		}

		TEST_METHOD(ScalarMultiplication)
		{
			vec3 a{ 1, -2, 3 };
			vec3 expected{ 3.5, -7, 10.5 };
			vec3 result = a * 3.5;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(FractionalMultiplication)
		{
			vec3 a{ 1, -2, 3 };
			vec3 expected{ 0.5, -1, 1.5 };
			vec3 result = a * 0.5;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(ScalarDivision)
		{
			vec3 a{ 1, -2, 3 };
			vec3 expected{ 0.5, -1, 1.5 };
			vec3 result = a / 2;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Magnitude)
		{
			vec3 v{ 1, 0, 0 };
			float expected = 1.0;
			float actual = v.magnitude();

			Assert::AreEqual(expected, actual);

			v = vec3{ 0, 1, 0 };
			expected = 1.0;
			actual = v.magnitude();

			Assert::AreEqual(expected, actual);

			v = vec3{ 0, 0, 1 };
			expected = 1.0;
			actual = v.magnitude();

			Assert::AreEqual(expected, actual);

			v = vec3{ 1, 2, 3 };
			expected = sqrtf(14);
			actual = v.magnitude();

			Assert::AreEqual(expected, actual);

			v = vec3{ -1, -2, -3 };
			expected = sqrtf(14);
			actual = v.magnitude();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Normalize)
		{
			vec3 v{ 4, 0, 0 };
			auto expected = vec3{ 1, 0, 0 };
			auto actual = v.normalize();
			
			Assert::IsTrue(floatEqual(1.0f, actual.magnitude()));

			v = vec3{ 1, 2, 3 };
			expected = vec3{ 0.26726f, 0.53452f, 0.80178f };
			actual = v.normalize();
			
			Assert::IsTrue(floatEqual(1.0f, actual.magnitude()));
		}

		TEST_METHOD(DotProduct)
		{
			vec3 a{ 1, 2, 3 };
			vec3 b{ 2, 3, 4 };

			auto expected = 20.0f;
			auto actual = dot(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CrossProduct)
		{
			vec3 a{ 1, 2, 3 };
			vec3 b{ 2, 3, 4 };

			vec3 expected{ -1, 2, -1 };
			auto actual = cross(a, b);

			Assert::AreEqual(expected, actual);

			expected = vec3{ 1, -2, 1 };
			actual = cross(b, a);
			Assert::AreEqual(expected, actual);
		}
	};
}
