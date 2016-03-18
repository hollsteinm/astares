#ifndef VECTOR2_H
#define VECTOR2_H

#include "../core/Types.h"

struct Vector2 {
	~Vector2();
	Vector2(f32 x, f32 y);
	Vector2();
	Vector2(f32 x);
	Vector2(const Vector2& other);

	Vector2 GetNormalized() const;
	Vector2 GetInverse() const;

	f32 GetDot(const Vector2& other) const;
	f32 GetLength() const;
	f32 GetLengthSquared() const;

	Vector2& Normalize();
	Vector2& Invert();

	f32 GetDistance(const Vector2& other) const;
	f32 GetDistanceSquared(const Vector2& other) const;

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);

	Vector2 operator+(const f32& other) const;
	Vector2 operator-(const f32& other) const;
	Vector2 operator*(const f32& a) const;
	Vector2 operator/(const f32& a) const;
	Vector2& operator+=(const f32& other);
	Vector2& operator-=(const f32& other);
	Vector2& operator*=(const f32& a);
	Vector2& operator/=(const f32& a);

	friend Vector2 operator+(const f32& lhs, const Vector2& rhs);
	friend Vector2 operator-(const f32& lhs, const Vector2& rhs);
	friend Vector2 operator*(const f32& lhs, const Vector2& rhs);
	friend Vector2 operator/(const f32& lhs, const Vector2& rhs);

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	f32& operator[](int32 index);
	const f32& operator[](int32 index) const;

	int32 ToBuffer(f32 out_buffer[2]) const;
	const std::string ToString() const;

	f32 data[2];

};


#endif