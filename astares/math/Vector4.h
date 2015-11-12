#ifndef VECTOR4_H
#define VECTOR4_H

#include <string>


struct Vector2;
struct Vector3;

struct Vector4 {
	~Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4();
	Vector4(float x);
	Vector4(float x, float y);
	Vector4(float x, float y, float w);
	Vector4(const Vector4& other);
	Vector4(const Vector3& other);
	Vector4(const Vector2& other);

	Vector4 GetNormalized() const;
	Vector4 GetInverse() const;

	float GetDot(const Vector4& other) const;
	float GetLength() const;
	float GetLengthSquared() const;

	Vector4& Normalize();
	Vector4& Invert();

	float GetDistance(const Vector4& other) const;
	float GetDistanceSquared(const Vector4& other) const;

	Vector4 operator+(const Vector2& other) const;
	Vector4 operator-(const Vector2& other) const;
	Vector4 operator+(const Vector3& other) const;
	Vector4 operator-(const Vector3& other) const;
	Vector4 operator+(const Vector4& other) const;
	Vector4 operator-(const Vector4& other) const;
	Vector4& operator+=(const Vector2& other);
	Vector4& operator-=(const Vector2& other);
	Vector4& operator+=(const Vector3& other);
	Vector4& operator-=(const Vector3& other);
	Vector4& operator+=(const Vector4& other);
	Vector4& operator-=(const Vector4& other);

	Vector4 operator+(const float& other) const;
	Vector4 operator-(const float& other) const;
	Vector4 operator*(const float& a) const;
	Vector4 operator/(const float& a) const;
	Vector4& operator+=(const float& other);
	Vector4& operator-=(const float& other);
	Vector4& operator*=(const float& a);
	Vector4& operator/=(const float& a);

	friend Vector4 operator+(const float& lhs, const Vector4& rhs);
	friend Vector4 operator-(const float& lhs, const Vector4& rhs);
	friend Vector4 operator*(const float& lhs, const Vector4& rhs);
	friend Vector4 operator/(const float& lhs, const Vector4& rhs);

	bool operator==(const Vector4& other) const;
	bool operator!=(const Vector4& other) const;

	float& operator[](int index);
	const float& operator[](int index) const;

	int ToBuffer(float out_buffer[4]) const;
	const std::string ToString() const;

	float data[4];
};


#endif