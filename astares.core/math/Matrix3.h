#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector.h"
#include "Matrix2.h"

//col-major
namespace astares {

	struct ASTARESCORE_API Matrix3 {
		Matrix3();
		Matrix3(const Matrix3& other);

		~Matrix3();

		Matrix3(const Vector3& col0);
		Matrix3(const Vector3& col0, const Vector3& col1);
		Matrix3(const Vector3& col0, const Vector3& col1, const Vector3& col2);
		Matrix3(const Vector2& col0);
		Matrix3(const Vector2& col0, const Vector2& col1);
		Matrix3(const Vector2& col0, const Vector2& col1, const Vector2& col2);

		Matrix3& Transpose();
		Matrix3& Inverse();
		Matrix3& Adjoint();
		Matrix3& CofactorMatrix();

		Matrix3 GetTranspose() const;
		Matrix3 GetInverse() const;
		Matrix3 GetAdjoint() const;
		Matrix3 GetCofactorMatrix() const;

		Matrix2 GetMinor(int32 row, int32 col) const;

		f32 GetDeterminant() const;
		f32 GetCofactor(int32 row, int32 col);

		Matrix3 operator+(const Matrix3& other) const;
		Matrix3 operator-(const Matrix3& other) const;
		Matrix3 operator*(f32 a) const;
		Matrix3 operator*(const Matrix3& other) const;
		Matrix3 operator/(f32 b) const;

		Matrix3& operator+=(const Matrix3& other);
		Matrix3& operator-=(const Matrix3& other);
		Matrix3& operator*=(f32 a);
		Matrix3& operator/=(f32 b);

		Vector3 operator*(const Vector3& vec) const;

		bool operator==(const Matrix3& other) const;
		bool operator!=(const Matrix3& other) const;

		Vector3& operator[](int32 col);
		const Vector3& operator[](int32 col) const;

		f32& operator()(int32 row, int32 col);
		const f32& operator()(int32 row, int32 col) const;

		int32 ToBuffer(f32 Out[3][3], bool transpose = false);
		const string ToString() const;

		Vector3 m[3];

		static const Matrix3 Identity;
	};

}
#endif