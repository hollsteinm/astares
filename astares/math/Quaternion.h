#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"


struct Quaternion {
	float w;
	float x;
	float y;
	float z;

	Quaternion();
	Quaternion(const Vector3& axis, float angle);
	Quaternion(const float x, const float y, const float z, const float w);

	Quaternion& Rotate(const Vector3& axis, float angle);

	Quaternion GetNormalized() const;

	float GetDot(const Quaternion& other) const;
	float GetLength() const;
	float GetLengthSquared() const;

	Quaternion& Normalize();

	float GetDistance(const Quaternion& other) const;
	float GetDistanceSquared(const Quaternion& other) const;

	Quaternion operator+(const Quaternion& other) const;
	Quaternion operator-(const Quaternion& other) const;
	Quaternion operator*(float a) const;
	Quaternion operator/(float b) const;

	Quaternion& operator+=(const Quaternion& other);
	Quaternion& operator-=(const Quaternion& other);
	Quaternion& operator*=(float a);
	Quaternion& operator/=(float b);

	bool operator==(const Quaternion& other) const;
	bool operator!=(const Quaternion& other) const;

	float& operator[](int index);
	const float& operator[](int index) const;

	int ToBuffer(float out_buffer[4]) const;
	const String ToString() const;
};


#endif