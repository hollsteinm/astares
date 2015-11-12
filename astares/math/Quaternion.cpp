#include "Quaternion.h"

#include "Vector.h"
#include "Math.h"

Quaternion::Quaternion() :
	x(0.0f),
	y(0.0f),
	z(0.0f),
	w(0.0f)
{

}

Quaternion::Quaternion(const Vector3& axis, float angle) : 
	x(axis[0]),
	y(axis[1]),
	z(axis[2]),
	w(angle)
{
}

Quaternion::Quaternion(const float x, const float y, const float z, const float w) :
	x(x),
	y(y),
	z(z),
	w(w)
{

}

Quaternion& Quaternion::Rotate(const Vector3& axis, float angle) {
	return *this;
}

float Quaternion::GetDot(const Quaternion& other) const {
	return x * other[0] + y * other[1] + z * other[2] + w * other[3];
}

float Quaternion::GetLength() const {
	return Math::SquareRoot(GetLengthSquared());
}

float Quaternion::GetLengthSquared() const {
	return x * x + y * y + z * z + w * w;
}

Quaternion Quaternion::GetNormalized() const {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		return Quaternion(x * recip, y * recip, z * recip, w * recip);
	}
	else {
		return Quaternion(0, 0, 0, 0);
	}
}

Quaternion& Quaternion::Normalize() {
	float l = GetLengthSquared();
	if (l != 0.0f) {
		float recip = Math::InverseSquareRoot(l);
		x *= recip;
		y *= recip;
		z *= recip;
		w *= recip;
		return *this;
	}
	else {
		x = y = z = w = 0.0f;
		return *this;
	}
}

float Quaternion::GetDistance(const Quaternion& other) const {
	return Quaternion(x - other[0], y - other[1], z - other[2], w - other[3]).GetLength();
}

float Quaternion::GetDistanceSquared(const Quaternion& other) const {
	return Quaternion(x - other[0], y - other[1], z - other[2], w - other[3]).GetLengthSquared();
}

Quaternion Quaternion::operator+(const Quaternion& other) const {
	return Quaternion(x + other[0], y + other[1], z + other[2], w + other[3]);
}

Quaternion Quaternion::operator-(const Quaternion& other) const {
	return Quaternion(x - other[0], y - other[1], z - other[2], w - other[3]);
}

Quaternion Quaternion::operator*(float a) const {
	return Quaternion(x * a, y * a, z * a, w * a);
}

Quaternion Quaternion::operator/(float b) const {
	return Quaternion(x / b, y / b, z / b, w / b);
}

Quaternion& Quaternion::operator+=(const Quaternion& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Quaternion& Quaternion::operator*=(float a) {
	x *= a;
	y *= a;
	z *= a;
	w *= a;
	return *this;
}

Quaternion& Quaternion::operator/=(float b) {
	x /= b;
	y /= b;
	z /= b;
	w /= b;
	return *this;
}

bool Quaternion::operator==(const Quaternion& other) const {
	return (x == other[0]) & (y == other[1]) & (z == other[2]) & (w == other[3]);
}

bool Quaternion::operator!=(const Quaternion& other) const {
	return (x != other[0]) & (y != other[1]) & (z != other[2]) & (w != other[3]);
}

int Quaternion::ToBuffer(float out_buffer[4]) const {
	out_buffer[X] = x;
	out_buffer[Y] = y;
	out_buffer[Z] = z;
	out_buffer[W] = w;
	
	return 4;
}

const std::string Quaternion::ToString() const {
	char buffer[128];
	size_t size = sprintf_s(buffer, 128, "[%f, %f, %f, %f]", x, y, z, w);
	return std::string(buffer, size);
}

float& Quaternion::operator[](int index) {
	switch (index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		return w;
	}
}

const float& Quaternion::operator[](int index) const {
	switch (index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		return w;
	}
}