#include "Vector2.h"
#include "Math.h"
#include <cstdio>

Vector2::~Vector2() {
}

Vector2::Vector2(float x, float y)
{
	data[0] = x;
	data[1] = y;
}

Vector2::Vector2()
{
	data[0] = 0.0f;
	data[1] = 0.0f;
}

Vector2::Vector2(float x)
{
	data[0] = x;
	data[1] = 0.0f;
}

Vector2::Vector2(const Vector2& other) {
	data[0] = other[0];
	data[1] = other[1];
}

float Vector2::GetDot(const Vector2& other) const {
	return data[0] * other[0] + data[1] * other[1];
}

float Vector2::GetLength() const {
	return Math::SquareRoot(GetLengthSquared());
}

float Vector2::GetLengthSquared() const {
	return data[0] * data[0] + data[1] * data[1];
}

Vector2 Vector2::GetNormalized() const {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		return Vector2(data[0] * recip, data[1] * recip);
	}
	else {
		return Vector2(0, 0);
	}
}

Vector2 Vector2::GetInverse() const {
	return Vector2(-data[0], -data[1]);
}

Vector2& Vector2::Normalize() {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		data[0] *= recip;
		data[1] *= recip;
		return *this;
	}
	else {
		data[0] = data[1] = 0.0f;
		return *this;
	}
}

Vector2& Vector2::Invert() {
	data[0] = -data[0];
	data[1] = -data[1];
	return *this;
}

float Vector2::GetDistance(const Vector2& other) const {
	return Vector2(data[0] - other[0], data[1] - other[1]).GetLength();
}

float Vector2::GetDistanceSquared(const Vector2& other) const {
	return Vector2(data[0] - other[0], data[1] - other[1]).GetLengthSquared();
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(data[0] + other[0], data[1] + other[1]);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(data[0] - other[0], data[1] - other[1]);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	data[0] += other[0];
	data[1] += other[1];
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	return *this;
}

Vector2 Vector2::operator+(const float& other) const {
	return Vector2(data[0] + other, data[1] + other);
}

Vector2 Vector2::operator-(const float& other) const {
	return Vector2(data[0] - other, data[1] - other);
}

Vector2 Vector2::operator*(const float& a) const {
	return Vector2(data[0] * a, data[1] * a);
}

Vector2 Vector2::operator/(const float& a) const {
	return Vector2(data[0] / a, data[1] / a);
}

Vector2& Vector2::operator+=(const float& other) {
	data[0] += other;
	data[1] += other;
	return *this;
}

Vector2& Vector2::operator-=(const float& other) {
	data[0] -= other;
	data[1] -= other;
	return *this;
}

Vector2& Vector2::operator*=(const float& a) {
	data[0] *= a;
	data[1] *= a;
	return *this;
}

Vector2& Vector2::operator/=(const float& a) {
	data[0] /= a;
	data[1] /= a;
	return *this;
}

Vector2 operator+(const float& lhs, const Vector2& rhs) {
	return Vector2(lhs + rhs[0], lhs + rhs[1]);
}

Vector2 operator-(const float& lhs, const Vector2& rhs) {
	return Vector2(lhs - rhs[0], lhs - rhs[1]);
}

Vector2 operator*(const float& lhs, const Vector2& rhs) {
	return Vector2(lhs * rhs[0], lhs * rhs[1]);
}

Vector2 operator/(const float& lhs, const Vector2& rhs) {
	return Vector2(lhs / rhs[0], lhs / rhs[1]);
}

bool Vector2::operator==(const Vector2& other) const {
	return (data[0] == other[0]) & (data[1] == other[1]);
}

bool Vector2::operator!=(const Vector2& other) const {
	return (data[0] != other[0]) & (data[1] != other[1]);
}

int Vector2::ToBuffer(float* out_buffer) const {
	out_buffer = new float[2]{ data[0], data[1] };
	return 2;
}

const String Vector2::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f]", data[0], data[1]);
	return String(buffer, size);
}

float& Vector2::operator[](int index) {
	return data[index];
}

const float& Vector2::operator[](int index) const {
	return data[index];
}