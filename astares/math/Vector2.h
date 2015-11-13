#ifndef VECTOR2_H
#define VECTOR2_H

#include "../core/String.h"


struct Vector2 {
	~Vector2();
	Vector2(float x, float y);
	Vector2();
	Vector2(float x);
	Vector2(const Vector2& other);

	Vector2 GetNormalized() const;
	Vector2 GetInverse() const;

	float GetDot(const Vector2& other) const;
	float GetLength() const;
	float GetLengthSquared() const;

	Vector2& Normalize();
	Vector2& Invert();

	float GetDistance(const Vector2& other) const;
	float GetDistanceSquared(const Vector2& other) const;

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);

	Vector2 operator+(const float& other) const;
	Vector2 operator-(const float& other) const;
	Vector2 operator*(const float& a) const;
	Vector2 operator/(const float& a) const;
	Vector2& operator+=(const float& other);
	Vector2& operator-=(const float& other);
	Vector2& operator*=(const float& a);
	Vector2& operator/=(const float& a);

	friend Vector2 operator+(const float& lhs, const Vector2& rhs);
	friend Vector2 operator-(const float& lhs, const Vector2& rhs);
	friend Vector2 operator*(const float& lhs, const Vector2& rhs);
	friend Vector2 operator/(const float& lhs, const Vector2& rhs);

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	float& operator[](int index);
	const float& operator[](int index) const;

	int ToBuffer(float out_buffer[2]) const;
	const String ToString() const;

	float data[2];

};


#endif