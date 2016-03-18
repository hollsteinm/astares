#ifndef VECTOR4_H
#define VECTOR4_H

#include "../core/Types.h"

struct Vector2;
struct Vector3;

struct Vector4 {
	~Vector4();
	Vector4(f32 x, f32 y, f32 z, f32 w);
	Vector4();
	Vector4(f32 x);
	Vector4(f32 x, f32 y);
	Vector4(f32 x, f32 y, f32 w);
	Vector4(const Vector4& other);
	Vector4(const Vector3& other);
	Vector4(const Vector2& other);

	Vector4 GetNormalized() const;
	Vector4 GetInverse() const;

	f32 GetDot(const Vector4& other) const;
	f32 GetLength() const;
	f32 GetLengthSquared() const;

	Vector4& Normalize();
	Vector4& Invert();

	f32 GetDistance(const Vector4& other) const;
	f32 GetDistanceSquared(const Vector4& other) const;

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

	Vector4 operator+(const f32& other) const;
	Vector4 operator-(const f32& other) const;
	Vector4 operator*(const f32& a) const;
	Vector4 operator/(const f32& a) const;
	Vector4& operator+=(const f32& other);
	Vector4& operator-=(const f32& other);
	Vector4& operator*=(const f32& a);
	Vector4& operator/=(const f32& a);

	friend Vector4 operator+(const f32& lhs, const Vector4& rhs);
	friend Vector4 operator-(const f32& lhs, const Vector4& rhs);
	friend Vector4 operator*(const f32& lhs, const Vector4& rhs);
	friend Vector4 operator/(const f32& lhs, const Vector4& rhs);

	bool operator==(const Vector4& other) const;
	bool operator!=(const Vector4& other) const;

	f32& operator[](int32 index);
	const f32& operator[](int32 index) const;

	int32 ToBuffer(f32 out_buffer[4]) const;
	const std::string ToString() const;

	f32 data[4];
};


#endif