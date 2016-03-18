#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"


struct ASTARESCORE_API Quaternion {
	f32 w;
	f32 x;
	f32 y;
	f32 z;

	Quaternion();
	Quaternion(const Vector3& axis, f32 angle);
	Quaternion(const f32 x, const f32 y, const f32 z, const f32 w);

	Quaternion& Rotate(const Vector3& axis, f32 angle);

	Quaternion GetNormalized() const;

	f32 GetDot(const Quaternion& other) const;
	f32 GetLength() const;
	f32 GetLengthSquared() const;

	Quaternion& Normalize();

	f32 GetDistance(const Quaternion& other) const;
	f32 GetDistanceSquared(const Quaternion& other) const;

	Quaternion operator+(const Quaternion& other) const;
	Quaternion operator-(const Quaternion& other) const;
	Quaternion operator*(f32 a) const;
	Quaternion operator/(f32 b) const;

	Quaternion& operator+=(const Quaternion& other);
	Quaternion& operator-=(const Quaternion& other);
	Quaternion& operator*=(f32 a);
	Quaternion& operator/=(f32 b);

	bool operator==(const Quaternion& other) const;
	bool operator!=(const Quaternion& other) const;

	f32& operator[](int32 index);
	const f32& operator[](int32 index) const;

	int32 ToBuffer(f32 out_buffer[4]) const;
	const std::string ToString() const;
};


#endif