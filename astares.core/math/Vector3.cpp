#include "Vector3.h"
#include "Vector2.h"
#include "Math.h"

#include <cstdio>

Vector3::~Vector3() {
}

Vector3::Vector3(f32 x, f32 y, f32 z)
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

Vector3::Vector3(f32 x)
{
	data[0] = x;
	data[1] = 0.0f;
	data[2] = 0.0f;
}

Vector3::Vector3(f32 x, f32 y)
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

f32 Vector3::GetDot(const Vector3& other) const {
	return data[0] * other[0] + data[1] * other[1] + data[2] * other[2];
}

f32 Vector3::GetMagnitude() const {
	return Math::SquareRoot(GetLengthSquared());
}

f32 Vector3::GetLengthSquared() const {
	return (data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]);
}

Vector3 Vector3::GetNormalized() const {
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
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
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
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

f32 Vector3::GetDistance(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]).GetMagnitude();
}

f32 Vector3::GetDistanceSquared(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]).GetLengthSquared();
}

Vector3 Vector3::operator+(const Vector3& other) const {
	return Vector3(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
}

Vector3 Vector3::operator-(const Vector3& other) const {
	return Vector3(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
}

Vector3 Vector3::operator*(const f32& a) const {
	return Vector3(data[0] * a, data[1] * a, data[2] * a);
}

Vector3 Vector3::operator/(const f32& a) const {
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

Vector3& Vector3::operator*=(const f32& a) {
	data[0] *= a;
	data[1] *= a;
	data[2] *= a;
	return *this;
}

Vector3& Vector3::operator/=(const f32& a) {
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
	f32 x = data[1] * other[2] - other[1] * data[2];
	f32 y = data[2] * other[0] - other[2] * data[0];
	f32 z = data[0] * other[1] - other[0] * data[1];
	data[0] = x;
	data[1] = y;
	data[2] = z;
	return *this;
}

Vector3 Vector3::operator + (const f32& other) const {
	return Vector3(data[0] + other,
		data[1] + other,
		data[2] + other);
}

Vector3 Vector3::operator-(const f32& other) const {
	return Vector3(data[0] - other,
		data[1] - other,
		data[2] - other);
}

Vector3& Vector3::operator+=(const f32& other) {
	data[0] += other;
	data[1] += other;
	data[2] += other;
	return *this;
}

Vector3& Vector3::operator-=(const f32& other) {
	data[0] -= other;
	data[1] -= other;
	data[2] -= other;
	return *this;
}

Vector3 operator+(const f32& lhs, const Vector3& rhs) {
	return Vector3(lhs + rhs[0],
		lhs + rhs[1],
		lhs + rhs[2]);
}

Vector3 operator-(const f32& lhs, const Vector3& rhs) {
	return Vector3(lhs - rhs[0],
		lhs - rhs[1],
		lhs - rhs[2]);
}

Vector3 operator*(const f32& lhs, const Vector3& rhs) {
	return Vector3(lhs * rhs[0],
		lhs * rhs[1],
		lhs * rhs[2]);
}

Vector3 operator/(const f32& lhs, const Vector3& rhs) {
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

int32 Vector3::ToBuffer(f32* out_buffer) const {
	memcpy(out_buffer, &data[0], sizeof(f32) * 3);
	return 3;
}

const std::string Vector3::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f, %f]", data[0], data[1], data[2]);
	return std::string(buffer, size);
}

f32& Vector3::operator[](int32 index) {
	return data[index];
}

const f32& Vector3::operator[](int32 index) const {
	return data[index];
}