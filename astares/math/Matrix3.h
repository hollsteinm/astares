#ifndef MATRIX3_H
#define MATRIX3_H

#include "Vector.h"
#include "Matrix2.h"
#include <string>

//col-major


struct Matrix3 {
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

	Matrix2 GetMinor(int col, int row) const;

	float GetDeterminant() const;
	float GetCofactor(int col, int row);

	Matrix3 operator+(const Matrix3& other) const;
	Matrix3 operator-(const Matrix3& other) const;
	Matrix3 operator*(float a) const;
	Matrix3 operator*(const Matrix3& other) const;
	Matrix3 operator/(float b) const;

	Matrix3& operator+=(const Matrix3& other);
	Matrix3& operator-=(const Matrix3& other);
	Matrix3& operator*=(float a);
	Matrix3& operator/=(float b);

	Vector3 operator*(const Vector3& vec) const;

	friend Vector3& operator*=(Vector3& vec, const Matrix3& mat);

	friend Vector3 operator*(const Vector3& vec, const Matrix3& mat);
	friend Matrix3 operator*(const float f, const Matrix3& mat);

	bool operator==(const Matrix3& other) const;
	bool operator!=(const Matrix3& other) const;

	Vector3& operator[](int col);
	const Vector3& operator[](int col) const;

	float& operator()(int row, int col);
	const float& operator()(int row, int col) const;

	int ToBuffer(float Out[3][3], bool transpose = false);
	const std::string ToString() const;

	Vector3 m[3];

	static const Matrix3 Identity;
};


#endif