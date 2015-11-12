#ifndef MATRIX2_H
#define MATRIX2_H

#include "Vector.h"
#include <string>

//col-major

struct Matrix2 {
	Matrix2();
	Matrix2(const Matrix2& other);

	~Matrix2();

	Matrix2(const Vector2& col0);
	Matrix2(const Vector2& col0, const Vector2& col1);

	Matrix2& Transpose();
	Matrix2& Inverse();
	Matrix2& Adjoint();
	Matrix2& CofactorMatrix();

	Matrix2 GetTranspose() const;
	Matrix2 GetInverse() const;
	Matrix2 GetAdjoint() const;
	Matrix2 GetCofactorMatrix() const;

	float GetDeterminant() const;

	Vector2& operator[](int index);
	const Vector2& operator[](int index) const;

	Matrix2 operator+(const Matrix2& other) const;
	Matrix2 operator-(const Matrix2& other) const;
	Matrix2 operator*(float a) const;
	Matrix2 operator*(const Matrix2& other) const;
	Matrix2 operator/(float b) const;

	Vector2 operator*(const Vector2& vec) const;

	friend Vector2& operator*=(Vector2& vec, const Matrix2& mat);

	friend Vector2 operator*(const Vector2& vec, const Matrix2& mat);
	friend Matrix2 operator*(const float f, const Matrix2& mat);

	Matrix2& operator+=(const Matrix2& other);
	Matrix2& operator-=(const Matrix2& other);
	Matrix2& operator*=(float a);
	Matrix2& operator/=(float b);

	bool operator==(const Matrix2& other) const;
	bool operator!=(const Matrix2& other) const;

	int ToBuffer(float Out[2][2], bool transpose = false);
	const std::string ToString() const;

	float& operator()(int row, int col);
	const float& operator()(int row, int col) const;

	Vector2 m[2];

	static const Matrix2 Identity;
};


#endif