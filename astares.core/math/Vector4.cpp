#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Math.h"

#include <cstdio>

using namespace astares;


Vector4::~Vector4() {
}

Vector4::Vector4(f32 x, f32 y, f32 z, f32 w)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
	data[3] = w;
}

Vector4::Vector4() :
	Vector4(0.0f, 0.0f, 0.0f, 0.0f)
{
}

Vector4::Vector4(f32 x) :
	Vector4(x, 0.0f, 0.0f, 0.0f)
{
}

Vector4::Vector4(f32 x, f32 y) :
	Vector4(x, y, 0.0f, 0.0f)
{
}

Vector4::Vector4(f32 x, f32 y, f32 z) :
	Vector4(x, y, z, 0.0f)
{
}

Vector4::Vector4(const Vector4& other) :
	Vector4(other[0], other[1], other[2], other[3])
{
}

Vector4::Vector4(const Vector3& other) :
Vector4(other[0], other[1], other[2])
{
}

Vector4::Vector4(const Vector2& other) :
	Vector4(other[0], other[1], 0.0f, 0.0f)
{
}

f32 Vector4::GetDot(const Vector4& other) const {
	return data[0] * other[0] + data[1] * other[1] + data[2] * other[2] + data[3] * other[3];
}

f32 Vector4::GetMagnitude() const {
	return Math::SquareRoot(GetLengthSquared());
}

f32 Vector4::GetLengthSquared() const {
	return data[0] * data[0] + data[1] * data[1] + data[2] * data[2] + data[3] * data[3];
}

Vector4 Vector4::GetNormalized() const {
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
		return Vector4(data[0] * recip, data[1] * recip, data[2] * recip, data[3] * recip);
	}
	else {
		return Vector4(0, 0, 0, 0);
	}
}

Vector4 Vector4::GetInverse() const {
	return Vector4(-data[0], -data[1], -data[2], -data[3]);
}

Vector4& Vector4::Normalize() {
	f32 l = GetLengthSquared();
	if (l != 0.0f) {
		f32 recip = Math::InverseSquareRoot(l);
		data[0] *= recip;
		data[1] *= recip;
		data[2] *= recip;
		data[3] *= recip;
		return *this;
	}
	else {
		data[0] = data[1] = data[2] = data[3] = 0.0f;
		return *this;
	}
}

Vector4& Vector4::Invert() {
	data[0] = -data[0];
	data[1] = -data[1];
	data[2] = -data[2];
	data[3] = -data[3];
	return *this;
}

f32 Vector4::GetDistance(const Vector4& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1], data[2] - other[2], data[3] - other[3]).GetMagnitude();
}

f32 Vector4::GetDistanceSquared(const Vector4& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1], data[2] - other[2], data[3] - other[3]).GetLengthSquared();
}

Vector4 Vector4::operator+(const Vector4& other) const {
	return Vector4(data[0] + other[0], data[1] + other[1], data[2] + other[2], data[3] + other[3]);
}

Vector4 Vector4::operator-(const Vector4& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1], data[2] - other[2], data[3] - other[3]);
}

Vector4& Vector4::operator+=(const Vector4& other) {
	data[0] += other[0];
	data[1] += other[1];
	data[2] += other[2];
	data[3] += other[3];
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	data[2] -= other[2];
	data[3] -= other[3];
	return *this;
}

Vector4 Vector4::operator+(const f32& other) const {
	return Vector4(data[0] + other, data[1] + other, data[2] + other, data[3] + other);
}

Vector4 Vector4::operator-(const f32& other) const {
	return Vector4(data[0] - other, data[1] - other, data[2] - other, data[3] - other);
}

Vector4 Vector4::operator*(const f32& a) const {
	return Vector4(data[0] * a, data[1] * a, data[2] * a, data[3] * a);
}

Vector4 Vector4::operator/(const f32& a) const {
	return Vector4(data[0] / a, data[1] / a, data[2] / a, data[3] / a);
}

Vector4& Vector4::operator+=(const f32& other) {
	data[0] += other;
	data[1] += other;
	data[2] += other;
	data[3] += other;
	return *this;
}

Vector4& Vector4::operator-=(const f32& other) {
	data[0] -= other;
	data[1] -= other;
	data[2] -= other;
	data[3] -= other;
	return *this;
}

Vector4& Vector4::operator*=(const f32& a) {
	data[0] *= a;
	data[1] *= a;
	data[2] *= a;
	data[3] *= a;
	return *this;
}

Vector4& Vector4::operator/=(const f32& a) {
	data[0] /= a;
	data[1] /= a;
	data[2] /= a;
	data[3] /= a;
	return *this;
}

Vector4 operator+(const f32& lhs, const Vector4& rhs) {
	return Vector4(lhs + rhs[0], lhs + rhs[1], lhs + rhs[2], lhs + rhs[3]);
}

Vector4 operator-(const f32& lhs, const Vector4& rhs) {
	return Vector4(lhs - rhs[0], lhs - rhs[1], lhs - rhs[2], lhs - rhs[3]);
}

Vector4 operator*(const f32& lhs, const Vector4& rhs) {
	return Vector4(lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]);
}

Vector4 operator/(const f32& lhs, const Vector4& rhs) {
	return Vector4(lhs / rhs[0], lhs / rhs[1], lhs / rhs[2], lhs / rhs[3]);
}

Vector4& Vector4::operator+=(const Vector2& other) {
	data[0] += other[0];
	data[1] += other[1];
	return *this;
}

Vector4& Vector4::operator-=(const Vector2& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	return *this;
}

Vector4& Vector4::operator+=(const Vector3& other) {
	data[0] += other[0];
	data[1] += other[1];
	data[2] += other[2];
	return *this;
}

Vector4& Vector4::operator-=(const Vector3& other) {
	data[0] -= other[0];
	data[1] -= other[1];
	data[2] -= other[2];
	return *this;
}

Vector4 Vector4::operator+(const Vector2& other) const {
	return Vector4(data[0] + other[0], data[1] + other[1]);
}

Vector4 Vector4::operator-(const Vector2& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1]);
}

Vector4 Vector4::operator+(const Vector3& other) const {
	return Vector4(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
}

Vector4 Vector4::operator-(const Vector3& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
}

bool Vector4::operator==(const Vector4& other) const {
	return (data[0] == other[0]) & (data[1] == other[1]) & (data[2] == other[2]) & (data[3] == other[3]);
}

bool Vector4::operator!=(const Vector4& other) const {
	return (data[0] != other[0]) & (data[1] != other[1]) & (data[2] != other[2]) & (data[3] != other[3]);
}

int32 Vector4::ToBuffer(f32* out_buffer) const {
	memcpy(out_buffer, &data[0], sizeof(f32) * 4);
	return 4;
}

const astares::cstring Vector4::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f, %f, %f]", data[0], data[1], data[2], data[3]);
	return buffer;
}

f32& Vector4::operator[](int32 index) {
	return data[index];
}

const f32& Vector4::operator[](int32 index) const {
	return data[index];
}