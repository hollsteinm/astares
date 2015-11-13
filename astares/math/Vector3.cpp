#include "Vector3.h"
#include "Vector2.h"
#include "Math.h"

#include <cstdio>

Vector3::~Vector3() {
}

Vector3::Vector3(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

Vector3::Vector3()
{
	data[0] = 0.0f;
	data[1] = 0.0f;
	data[2] = 0.0f;
}

Vector3::Vector3(float x)
{
	data[0] = x;
	data[1] = 0.0f;
	data[2] = 0.0f;
}

Vector3::Vector3(float x, float y)
{
	data[0] = x;
	data[1] = y;
	data[2] = 0.0f;
}

Vector3::Vector3(const Vector3& other)
{
	data[0] = other[0];
	data[1] = other[1];
	data[2] = other[2];
}

Vector3::Vector3(const Vector2& other)
{
	data[0] = other[0];
	data[1] = other[1];
	data[2] = 0.0f;
}

float Vector3::GetDot(const Vector3& other) const {
	return data[0] * other[0] + data[1] * other[1] + data[2] * other[2];
}

float Vector3::GetLength() const {
	return Math::SquareRoot(GetLengthSquared());
}

float Vector3::GetLengthSquared() const {
	return data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
}

Vector3 Vector3::GetNormalized() const {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		return Vector3(data[0] * recip, data[1] * recip, data[2] * recip);
	}
	else {
		return Vector3(0, 0);
	}
}

Vector3 Vector3::GetInverse() const {
	return Vector3(-data[0], -data[1], -data[2]);
}

//Right handed
Vector3 Vector3::GetOrthonormalBasis(Vector3& b, Vector3& c) const {
	Vector3 result = *this;
	result.Normalize();
	
	c = result.GetCross(b);
	c.Normalize();

	b = c.GetCross(result);

	return result;
}

Vector3& Vector3::Normalize() {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		data[0] *= recip;
		data[1] *= recip;
		data[2] *= recip;
		return *this;
	}
	else {
		data[0] = data[1] = data[2] = 0.0f;
		return *this;
	}
}

Vector3& Vector3::Invert() {
	data[0] = -data[0];
	data[1] = -data[1];
	data[2] = -data[2];
	return *this;
}

//Right handed
Vector3& Vector3::OrthonormalBasis(Vector3& b, Vector3& c) {
	Normalize();

	c = GetCross(b);
	c.Normalize();

	b = c.GetCross(*this);

	return *this;
}

float Vector3::GetDistance(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]).GetLength();
}

float Vector3::GetDistanceSquared(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]).GetLengthSquared();
}

Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
}

Vector3 Vector3::operator-(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
}

Vector3 Vector3::operator*(const float& a) const {
	return Vector3(data[0] * a, data[1] * a, data[2] * a);
}

Vector3 Vector3::operator/(const float& a) const {
	return Vector3(data[0] / a, data[1] / a, data[2] / a);
}

Vector3& Vector3::operator+=(const Vector3& other) {
	data[0] += other[0];
	data[1] += other[1];
	data[2] += other[2];
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	data[2] -= other[2];
	return *this;
}

Vector3& Vector3::operator*=(const float& a) {
	data[0] *= a;
	data[1] *= a;
	data[2] *= a;
	return *this;
}

Vector3& Vector3::operator/=(const float& a) {
	data[0] /= a;
	data[1] /= a;
	data[2] /= a;
	return *this;
}

Vector3& Vector3::operator+=(const Vector2& other) {
	data[0] += other[0];
	data[1] += other[1];
	return *this;
}

Vector3& Vector3::operator-=(const Vector2& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	return *this;
}

Vector3 Vector3::operator+(const Vector2& other) const {
	return Vector3(data[0] + other[0], data[1] + other[1], 0.0);
}

Vector3 Vector3::operator-(const Vector2& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], 0.0);
}

Vector3 Vector3::GetCross(const Vector3& other) const {
	return Vector3(data[1] * other[2] - other[1] * data[2],
		data[2] * other[0] - other[2] * data[0],
		data[0] * other[1] - other[0] * data[1]);
}

Vector3& Vector3::Cross(const Vector3& other) {
	float x = data[1] * other[2] - other[1] * data[2];
	float y = data[2] * other[0] - other[2] * data[0];
	float z = data[0] * other[1] - other[0] * data[1];
	data[0] = x;
	data[1] = y;
	data[2] = z;
	return *this;
}

Vector3 Vector3::operator + (const float& other) const {
	return Vector3(data[0] + other,
		data[1] + other,
		data[2] + other);
}

Vector3 Vector3::operator-(const float& other) const {
	return Vector3(data[0] - other,
		data[1] - other,
		data[2] - other);
}

Vector3& Vector3::operator+=(const float& other) {
	data[0] += other;
	data[1] += other;
	data[2] += other;
	return *this;
}

Vector3& Vector3::operator-=(const float& other) {
	data[0] -= other;
	data[1] -= other;
	data[2] -= other;
	return *this;
}

Vector3 operator+(const float& lhs, const Vector3& rhs) {
	return Vector3(lhs + rhs[0],
		lhs + rhs[1],
		lhs + rhs[2]);
}

Vector3 operator-(const float& lhs, const Vector3& rhs) {
	return Vector3(lhs - rhs[0],
		lhs - rhs[1],
		lhs - rhs[2]);
}

Vector3 operator*(const float& lhs, const Vector3& rhs) {
	return Vector3(lhs * rhs[0],
		lhs * rhs[1],
		lhs * rhs[2]);
}

Vector3 operator/(const float& lhs, const Vector3& rhs) {
	return Vector3(lhs / rhs[0],
		lhs / rhs[1],
		lhs / rhs[2]);
}

bool Vector3::operator==(const Vector3& other) const {
	return (data[0] == other[0]) & (data[1] == other[1]) & (data[2] == other[2]);
}

bool Vector3::operator!=(const Vector3& other) const {
	return (data[0] != other[0]) & (data[1] != other[1]) & (data[2] != other[2]);
}

int Vector3::ToBuffer(float* out_buffer) const {
	memcpy(out_buffer, &data[0], sizeof(float) * 3);
	return 3;
}

const String Vector3::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f, %f]", data[0], data[1], data[2]);
	return String(buffer, size);
}

float& Vector3::operator[](int index) {
	return data[index];
}

const float& Vector3::operator[](int index) const {
	return data[index];
}