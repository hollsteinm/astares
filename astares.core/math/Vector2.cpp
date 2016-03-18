#include "Vector2.h"
#include "Math.h"
#include <cstdio>

Vector2::~Vector2() {
}

Vector2::Vector2(f32 x, f32 y)
{
	data[0] = x;
	data[1] = y;
}

Vector2::Vector2()
{
	data[0] = 0.0f;
	data[1] = 0.0f;
}

Vector2::Vector2(f32 x)
{
	data[0] = x;
	data[1] = 0.0f;
}

Vector2::Vector2(const Vector2& other) {
	data[0] = other[0];
	data[1] = other[1];
}

f32 Vector2::GetDot(const Vector2& other) const {
	return data[0] * other[0] + data[1] * other[1];
}

f32 Vector2::GetLength() const {
	return Math::SquareRoot(GetLengthSquared());
}

f32 Vector2::GetLengthSquared() const {
	return data[0] * data[0] + data[1] * data[1];
}

Vector2 Vector2::GetNormalized() const {
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
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
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
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

f32 Vector2::GetDistance(const Vector2& other) const {
	return Vector2(data[0] - other[0], data[1] - other[1]).GetLength();
}

f32 Vector2::GetDistanceSquared(const Vector2& other) const {
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

Vector2 Vector2::operator+(const f32& other) const {
	return Vector2(data[0] + other, data[1] + other);
}

Vector2 Vector2::operator-(const f32& other) const {
	return Vector2(data[0] - other, data[1] - other);
}

Vector2 Vector2::operator*(const f32& a) const {
	return Vector2(data[0] * a, data[1] * a);
}

Vector2 Vector2::operator/(const f32& a) const {
	return Vector2(data[0] / a, data[1] / a);
}

Vector2& Vector2::operator+=(const f32& other) {
	data[0] += other;
	data[1] += other;
	return *this;
}

Vector2& Vector2::operator-=(const f32& other) {
	data[0] -= other;
	data[1] -= other;
	return *this;
}

Vector2& Vector2::operator*=(const f32& a) {
	data[0] *= a;
	data[1] *= a;
	return *this;
}

Vector2& Vector2::operator/=(const f32& a) {
	data[0] /= a;
	data[1] /= a;
	return *this;
}

bool Vector2::operator==(const Vector2& other) const {
	return (data[0] == other[0]) & (data[1] == other[1]);
}

bool Vector2::operator!=(const Vector2& other) const {
	return (data[0] != other[0]) & (data[1] != other[1]);
}

int32 Vector2::ToBuffer(f32* out_buffer) const {
	out_buffer[0] = data[0];
	out_buffer[1] = data[1];
	return 2;
}

const std::string Vector2::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f]", data[0], data[1]);
	return std::string(buffer, size);
}

f32& Vector2::operator[](int32 index) {
	return data[index];
}

const f32& Vector2::operator[](int32 index) const {
	return data[index];
}