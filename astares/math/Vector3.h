#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>


struct Vector2;

struct Vector3 {
	~Vector3();
	Vector3(float x, float y, float z);
	Vector3();
	Vector3(float x);
	Vector3(float x, float y);
	Vector3(const Vector3& other);
	Vector3(const Vector2& other);

	Vector3 GetCross(const Vector3& other) const;
	Vector3 GetNormalized() const;
	Vector3 GetInverse() const;
	Vector3 GetOrthonormalBasis(Vector3& b, Vector3& c) const;

	float GetDot(const Vector3& other) const;
	float GetLength() const;
	float GetLengthSquared() const;

	Vector3& Cross(const Vector3& other);
	Vector3& Normalize();
	Vector3& Invert();
	Vector3& OrthonormalBasis(Vector3& b, Vector3& c);

	float GetDistance(const Vector3& other) const;
	float GetDistanceSquared(const Vector3& other) const;

	Vector3 operator+(const Vector2& other) const;
	Vector3 operator-(const Vector2& other) const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3& operator+=(const Vector2& other);
	Vector3& operator-=(const Vector2& other);
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	Vector3 operator+(const float& other) const;
	Vector3 operator-(const float& other) const;
	Vector3 operator*(const float& a) const;
	Vector3 operator/(const float& a) const;
	Vector3& operator+=(const float& other);
	Vector3& operator-=(const float& other);
	Vector3& operator*=(const float& a);
	Vector3& operator/=(const float& a);

	friend Vector3 operator+(const float& lhs, const Vector3& rhs);
	friend Vector3 operator-(const float& lhs, const Vector3& rhs);
	friend Vector3 operator*(const float& lhs, const Vector3& rhs);
	friend Vector3 operator/(const float& lhs, const Vector3& rhs);

	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

	float& operator[](int index);
	const float& operator[](int index) const;

	int ToBuffer(float out_buffer[3]) const;
	const std::string ToString() const;

	float data[3];

};

#endif