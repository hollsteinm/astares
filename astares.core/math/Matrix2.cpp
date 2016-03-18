#include "Matrix2.h"
#include "Math.h"

const Matrix2 Matrix2::Identity = Matrix2(Vector2(1.0f, 0.0), Vector2(0.0f, 1.0f));

Matrix2::Matrix2() {
	*this = Identity;
}

Matrix2::Matrix2(const Matrix2& other) {
	m[0] = other.m[0];
	m[1] = other.m[1];
}

Matrix2::~Matrix2() {

}

Matrix2::Matrix2(const Vector2& col0) {
	m[0] = col0;
}

Matrix2::Matrix2(const Vector2& col0, const Vector2& col1) : 
	Matrix2(col0)
{
	m[1] = col1;
}

Matrix2& Matrix2::Transpose() {
	m[0] = Vector2(m[0][0], m[1][0]);
	m[1] = Vector2(m[0][1], m[1][1]);
	return *this;
}

Matrix2& Matrix2::Adjoint() {
	return CofactorMatrix().Transpose();
}

Matrix2& Matrix2::CofactorMatrix() {
	Matrix2 temp(*this);
	
	m[0][0] = temp[1][1]; m[1][0] = -temp[0][1];
	m[0][1] = -temp[1][0]; m[1][1] = temp[0][0];

	return *this;
}

Matrix2& Matrix2::Inverse() {
	f32 det = GetDeterminant();
	if (Math::LargerThanAlmostZero(det))
		return *this = Matrix2(Vector2(m[1][1], -m[0][1]), Vector2(-m[1][0], m[0][0])) * (1.0f / det);
	else return *this;
}

Matrix2 Matrix2::GetTranspose() const {
	return Matrix2(*this).Transpose();
}

Matrix2 Matrix2::GetAdjoint() const {
	return Matrix2(*this).Adjoint();
}

Matrix2 Matrix2::GetInverse() const {
	return Matrix2(*this).Inverse();
}

Matrix2 Matrix2::GetCofactorMatrix() const {
	return Matrix2(*this).CofactorMatrix();
}

f32 Matrix2::GetDeterminant() const {
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

Vector2& Matrix2::operator[](int32 index) {
	return m[index];
}

const Vector2& Matrix2::operator[](int32 index) const {
	return m[index];
}

Matrix2 Matrix2::operator+(const Matrix2& other) const {
	return Matrix2(m[0] + other[0], m[1] + other[1]);
}

Matrix2 Matrix2::operator-(const Matrix2& other) const {
	return Matrix2(m[0] + other[0], m[1] + other[1]);
}

Matrix2 Matrix2::operator*(f32 a) const {
	return Matrix2(m[0] * a, m[1] * a);
}

Matrix2 Matrix2::operator*(const Matrix2& other) const {
	Vector2 row0 = Vector2(m[0][0], m[1][0]);
	Vector2 row1 = Vector2(m[0][1], m[1][1]);

	return Matrix2(
		Vector2(row0.GetDot(other[0]), row0.GetDot(other[1])),
		Vector2(row1.GetDot(other[0]), row1.GetDot(other[1])));
}

Matrix2 Matrix2::operator/(f32 b) const {
	return Matrix2(m[0] / b, m[1] / b);
}

Matrix2& Matrix2::operator+=(const Matrix2& other) {
	m[0] += other[0];
	m[1] += other[1];
	return *this;
}

Matrix2& Matrix2::operator-=(const Matrix2& other) {
	m[0] -= other[0];
	m[1] -= other[1];
	return *this;
}

Matrix2& Matrix2::operator*=(f32 a) {
	m[0] *= a;
	m[1] *= a;
	return *this;
}

Matrix2& Matrix2::operator/=(f32 b) {
	m[0] /= b;
	m[1] /= b;
	return *this;
}

Vector2 Matrix2::operator*(const Vector2& vec) const {
	return Vector2(m[0][0] * vec[0] + m[1][0] * vec[1],	m[0][1] * vec[0] + m[1][1] * vec[1]);
}

Vector2& operator*=(Vector2& vec, const Matrix2& mat) {
	vec = mat * vec;
	return vec;
}

Vector2 operator*(const Vector2& vec, const Matrix2& mat) {
	return mat * vec;
}

Matrix2 operator*(const f32 f, const Matrix2& mat) {
	return mat * f;
}

bool Matrix2::operator==(const Matrix2& other) const {
	return (m[0] == other.m[0]) & (m[1] == other.m[1]);
}

bool Matrix2::operator!=(const Matrix2& other) const {
	return (m[0] != other.m[0]) & (m[1] != other.m[1]);
}

int32 Matrix2::ToBuffer(f32 Out[2][2], bool transpose) {
	f32 col0[2];
	f32 col1[2];

	if (transpose) {
		Matrix2 useInstead = GetTranspose();
		useInstead.m[0].ToBuffer(col0);
		useInstead.m[1].ToBuffer(col1);
	}
	else {
		m[0].ToBuffer(col0);
		m[1].ToBuffer(col1);
	}

	Out[0][0] = col0[0];
	Out[0][1] = col0[1];
	Out[1][0] = col1[0];
	Out[1][1] = col1[1];

	return 4;
}

const std::string Matrix2::ToString() const {
	char buffer[256];
	size_t size = sprintf_s(buffer, "[%f, %f]\n[%f, %f]",
		m[0][0], m[1][0],
		m[0][1], m[1][1]);
	return std::string(buffer, size);
}

f32& Matrix2::operator()(int32 row, int32 col) {
	return m[col][row];
}

const f32& Matrix2::operator()(int32 row, int32 col) const {
	return m[col][row];
}