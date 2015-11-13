#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Math.h"

#include <cstdio>


Vector4::~Vector4() {
}

Vector4::Vector4(float x, float y, float z, float w)
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

Vector4::Vector4(float x) :
	Vector4(x, 0.0f, 0.0f, 0.0f)
{
}

Vector4::Vector4(float x, float y) :
	Vector4(x, y, 0.0f, 0.0f)
{
}

Vector4::Vector4(float x, float y, float z) :
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

float Vector4::GetDot(const Vector4& other) const {
	return data[0] * other[0] + data[1] * other[1] + data[2] * other[2] + data[3] * other[3];
}

float Vector4::GetLength() const {
	return Math::SquareRoot(GetLengthSquared());
}

float Vector4::GetLengthSquared() const {
	return data[0] * data[0] + data[1] * data[1] + data[2] * data[2] + data[3] * data[3];
}

Vector4 Vector4::GetNormalized() const {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
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
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
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

float Vector4::GetDistance(const Vector4& other) const {
	return Vector4(data[0] - other[0], data[1] - other[1], data[2] - other[2], data[3] - other[3]).GetLength();
}

float Vector4::GetDistanceSquared(const Vector4& other) const {
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

Vector4 Vector4::operator+(const float& other) const {
	return Vector4(data[0] + other, data[1] + other, data[2] + other, data[3] + other);
}

Vector4 Vector4::operator-(const float& other) const {
	return Vector4(data[0] - other, data[1] - other, data[2] - other, data[3] - other);
}

Vector4 Vector4::operator*(const float& a) const {
	return Vector4(data[0] * a, data[1] * a, data[2] * a, data[3] * a);
}

Vector4 Vector4::operator/(const float& a) const {
	return Vector4(data[0] / a, data[1] / a, data[2] / a, data[3] / a);
}

Vector4& Vector4::operator+=(const float& other) {
	data[0] += other;
	data[1] += other;
	data[2] += other;
	data[3] += other;
	return *this;
}

Vector4& Vector4::operator-=(const float& other) {
	data[0] -= other;
	data[1] -= other;
	data[2] -= other;
	data[3] -= other;
	return *this;
}

Vector4& Vector4::operator*=(const float& a) {
	data[0] *= a;
	data[1] *= a;
	data[2] *= a;
	data[3] *= a;
	return *this;
}

Vector4& Vector4::operator/=(const float& a) {
	data[0] /= a;
	data[1] /= a;
	data[2] /= a;
	data[3] /= a;
	return *this;
}

Vector4 operator+(const float& lhs, const Vector4& rhs) {
	return Vector4(lhs + rhs[0], lhs + rhs[1], lhs + rhs[2], lhs + rhs[3]);
}

Vector4 operator-(const float& lhs, const Vector4& rhs) {
	return Vector4(lhs - rhs[0], lhs - rhs[1], lhs - rhs[2], lhs - rhs[3]);
}

Vector4 operator*(const float& lhs, const Vector4& rhs) {
	return Vector4(lhs * rhs[0], lhs * rhs[1], lhs * rhs[2], lhs * rhs[3]);
}

Vector4 operator/(const float& lhs, const Vector4& rhs) {
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

int Vector4::ToBuffer(float* out_buffer) const {
	out_buffer = new float[4]{ data[0], data[1], data[2], data[3] };
	return 4;
}

const String Vector4::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f, %f, %f]", data[0], data[1], data[2], data[3]);
	return String(buffer, size);
}

float& Vector4::operator[](int index) {
	return data[index];
}

const float& Vector4::operator[](int index) const {
	return data[index];
}