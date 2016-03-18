#ifndef VECTOR3_H
#define VECTOR3_H

#include "../core/Types.h"


struct Vector2;

struct ASTARESCORE_API Vector3 {
	~Vector3();
	Vector3(f32 x, f32 y, f32 z);
	Vector3();
	Vector3(f32 x);
	Vector3(f32 x, f32 y);
	Vector3(const Vector3& other);
	Vector3(const Vector2& other);

	Vector3 GetCross(const Vector3& other) const;
	Vector3 GetNormalized() const;
	Vector3 GetInverse() const;
	Vector3 GetOrthonormalBasis(Vector3& b, Vector3& c) const;

	f32 GetDot(const Vector3& other) const;
	f32 GetLength() const;
	f32 GetLengthSquared() const;

	Vector3& Cross(const Vector3& other);
	Vector3& Normalize();
	Vector3& Invert();
	Vector3& OrthonormalBasis(Vector3& b, Vector3& c);

	f32 GetDistance(const Vector3& other) const;
	f32 GetDistanceSquared(const Vector3& other) const;

	Vector3 operator+(const Vector2& other) const;
	Vector3 operator-(const Vector2& other) const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3& operator+=(const Vector2& other);
	Vector3& operator-=(const Vector2& other);
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	Vector3 operator+(const f32& other) const;
	Vector3 operator-(const f32& other) const;
	Vector3 operator*(const f32& a) const;
	Vector3 operator/(const f32& a) const;
	Vector3& operator+=(const f32& other);
	Vector3& operator-=(const f32& other);
	Vector3& operator*=(const f32& a);
	Vector3& operator/=(const f32& a);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

	f32& operator[](int32 index);
	const f32& operator[](int32 index) const;

	int32 ToBuffer(f32 out_buffer[3]) const;
	const std::string ToString() const;

	f32 data[3];

};

Vector3 operator+(const f32& lhs, const Vector3& rhs);
Vector3 operator-(const f32& lhs, const Vector3& rhs);
Vector3 operator*(const f32& lhs, const Vector3& rhs);
Vector3 operator/(const f32& lhs, const Vector3& rhs);

#endif