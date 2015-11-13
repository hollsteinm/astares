#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector.h"
#include "Matrix3.h"
#include "../core/String.h"

//col-major

struct Matrix4 {
	Matrix4();
	Matrix4(const Matrix4& other);

	~Matrix4();

	Matrix4(const Vector4& col0);
	Matrix4(const Vector4& col0, const Vector4& col1);
	Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2);
	Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2, const Vector4& col3);
	Matrix4(const Vector3& col0);
	Matrix4(const Vector3& col0, const Vector3& col1);
	Matrix4(const Vector3& col0, const Vector3& col1, const Vector3& col2);
	Matrix4(const Vector3& col0, const Vector3& col1, const Vector3& col2, const Vector3& col3);
	Matrix4(const Vector2& col0);
	Matrix4(const Vector2& col0, const Vector2& col1);
	Matrix4(const Vector2& col0, const Vector2& col1, const Vector2& col2);
	Matrix4(const Vector2& col0, const Vector2& col1, const Vector2& col2, const Vector2& col3);

	Matrix4& Transpose();
	Matrix4& Inverse();
	Matrix4& Adjoint();
	Matrix4& CofactorMatrix();

	Matrix4 GetTranspose() const;
	Matrix4 GetInverse() const;
	Matrix4 GetAdjoint() const;
	Matrix4 GetCofactorMatrix() const;

	Matrix3 GetMinor(int col, int row) const;

	float GetDeterminant() const;
	float GetCofactor(int col, int row);

	Matrix4 operator+(const Matrix4& other) const;
	Matrix4 operator-(const Matrix4& other) const;
	Matrix4 operator*(float a) const;
	Matrix4 operator*(const Matrix4& other) const;
	Matrix4 operator/(float b) const;

	Matrix4& operator+=(const Matrix4& other);
	Matrix4& operator-=(const Matrix4& other);
	Matrix4& operator*=(float a);
	Matrix4& operator/=(float b);

	Vector4 operator*(const Vector4& vec) const;

	friend Vector4& operator*=(Vector4& vec, const Matrix4& mat);

	friend Vector4 operator*(const Vector4& vec, const Matrix4& mat);
	friend Matrix4 operator*(const float f, const Matrix4& mat);

	bool operator==(const Matrix4& other) const;
	bool operator!=(const Matrix4& other) const;

	Vector4& operator[](int col);
	const Vector4& operator[](int col) const;

	float& operator()(int row, int col);
	const float& operator()(int row, int col) const;

	int ToBuffer(float Out[4][4], bool transpose = false);
	const String ToString() const;

	Vector4 m[4];

	static const Matrix4 Identity;
};


#endif