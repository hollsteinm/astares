#include "Matrix3.h"
#include "Matrix2.h"
#include "Math.h"

const Matrix3 Matrix3::Identity = Matrix3(Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f));

Matrix3::Matrix3()
{
	*this = Matrix3::Identity;
}

Matrix3::Matrix3(const Matrix3& other)
{
	m[0] = other.m[0];
	m[1] = other.m[1];
	m[2] = other.m[2];
}

Matrix3::~Matrix3() {

}

Matrix3::Matrix3(const Vector3& col0)
{
	m[0] = col0;
}

Matrix3::Matrix3(const Vector3& col0, const Vector3& col1)
	: Matrix3(col0)
{
	m[1] = col1;
}

Matrix3::Matrix3(const Vector3& col0, const Vector3& col1, const Vector3& col2)
	: Matrix3(col0, col1)
{
	m[2] = col2;
}

Matrix3::Matrix3(const Vector2& col0)
	: Matrix3(Vector3(col0))
{
}

Matrix3::Matrix3(const Vector2& col0, const Vector2& col1)
	: Matrix3(Vector3(col0), Vector3(col1))
{
}

Matrix3::Matrix3(const Vector2& col0, const Vector2& col1, const Vector2& col2)
	: Matrix3(Vector3(col0), Vector3(col1), Vector3(col2))
{
}

Matrix3& Matrix3::Transpose() {
	Matrix3 temp(*this);

	m[0][0] = temp[0][0];	m[1][0] = temp[0][1];	m[2][0] = temp[0][2];

	m[0][1] = temp[1][0];	m[1][1] = temp[1][1];	m[2][1] = temp[1][2];

	m[0][2] = temp[2][0];	m[1][2] = temp[2][1];	m[2][2] = temp[2][2];

	return *this;
}

Matrix3& Matrix3::Inverse() {
	f32 det = GetDeterminant();
	if (Math::LargerThanAlmostZero(det))
		return Adjoint() *= (1.0f / det);
	else return *this;
}

Matrix3& Matrix3::Adjoint() {
	CofactorMatrix();
	return Transpose();
}

Matrix3 Matrix3::GetTranspose() const {
	return Matrix3(*this).Transpose();
}

Matrix3 Matrix3::GetInverse() const {
	return Matrix3(*this).Inverse();
}

f32 Matrix3::GetDeterminant() const {
	f32 e = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]);
	f32 f = m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]);
	f32 g = m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

	return e - f + g;
}

Matrix3 Matrix3::GetAdjoint() const {
	return Matrix3(*this).Adjoint();
}

Matrix3 Matrix3::GetCofactorMatrix() const {
	return Matrix3(*this).CofactorMatrix();
}

Matrix2 Matrix3::GetMinor(int32 row, int32 col) const {
	int32 col0, col1, row0, row1 = 0;

	switch (row)
	{
	case 0:
		col0 = 1;
		col1 = 2;
		break;
	case 1:
		col0 = 0;
		col1 = 2;
		break;
	case 2:
		col0 = 0;
		col1 = 1;
		break;
	}

	switch (col)
	{
	case 0:
		row0 = 1;
		row1 = 2;
		break;
	case 1:
		row0 = 0;
		row1 = 2;
		break;
	case 2:
		row0 = 0;
		row1 = 1;
		break;
	}

	Vector2 vec0 = Vector2(m[col0][row0], m[col0][row1]);
	Vector2 vec1 = Vector2(m[col1][row0], m[col1][row1]);

	return Matrix2(vec0, vec1);
}

f32 Matrix3::GetCofactor(int32 row, int32 col) {

	static const f32 signs[3][3] = {
		1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, -1.0f,
		1.0f, -1.0f, 1.0f
	};

	return GetMinor(row, col).GetDeterminant() * signs[col][row];
}

Matrix3& Matrix3::CofactorMatrix() {
	Matrix3 temp(*this);
	for (int32 row = 0; row < 3; ++row) {
		for (int32 col = 0; col < 3; ++col) {
			temp[col][row] = GetCofactor(col, row);
		}
	}
	*this = temp;
	return *this;
}

Matrix3 Matrix3::operator+(const Matrix3& other) const {
	return Matrix3(m[0] + other[0], m[1] + other[1], m[2] + other[2]);
}

Matrix3 Matrix3::operator-(const Matrix3& other) const {
	return Matrix3(m[0] - other[0], m[1] - other[1], m[2] - other[2]);
}

Matrix3 Matrix3::operator*(f32 a) const {
	return Matrix3(m[0] * a, m[1] * a, m[2] * a);
}

Matrix3 Matrix3::operator*(const Matrix3& other) const {
	return
	{
		{
			m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0],
			m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1],
			m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2]
		},
		{
			m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0],
			m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1],
			m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2]
		},
		{
			m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0],
			m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1],
			m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2]
		}
	};
}

Matrix3 Matrix3::operator/(f32 b) const {
	return Matrix3(m[0] / b, m[1] / b, m[2] / b);
}

Matrix3& Matrix3::operator+=(const Matrix3& other) {
	m[0] += other[0];
	m[1] += other[1];
	m[2] += other[2];
	return *this;
}

Matrix3& Matrix3::operator-=(const Matrix3& other) {
	m[0] -= other[0];
	m[1] -= other[1];
	m[2] -= other[2];
	return *this;
}

Matrix3& Matrix3::operator*=(f32 a) {
	m[0] *= a;
	m[1] *= a;
	m[2] *= a;
	return *this;
}

Matrix3& Matrix3::operator/=(f32 b) {
	m[0] /= b;
	m[1] /= b;
	m[2] /= b;
	return *this;
}

Vector3 Matrix3::operator*(const Vector3& vec) const {
	return Vector3(
		m[0][0] * vec[0] + m[0][1] * vec[1] + m[0][2] * vec[2],
		m[1][0] * vec[0] + m[1][1] * vec[1] + m[1][2] * vec[2],
		m[2][0] * vec[0] + m[2][1] * vec[1] + m[2][2] * vec[2]
		);
}

bool Matrix3::operator==(const Matrix3& other) const {
	return (m[0] == other.m[0]) & (m[1] == other.m[1]) & (m[2] == other.m[2]);
}

bool Matrix3::operator!=(const Matrix3& other) const {
	return (m[0] != other.m[0]) & (m[1] != other.m[1]) & (m[2] != other.m[2]);
}

Vector3& Matrix3::operator[](int32 col) {
	return m[col];
}

const Vector3& Matrix3::operator[](int32 col) const {
	return m[col];
}

f32& Matrix3::operator()(int32 row, int32 col) {
	return m[col][row];
}

const f32& Matrix3::operator()(int32 row, int32 col) const {
	return m[col][row];
}

int32 Matrix3::ToBuffer(f32 Out[3][3], bool transpose) {
	f32 col0[3];
	f32 col1[3];
	f32 col2[3];

	if (transpose) {
		Matrix3 useInstead = GetTranspose();
		useInstead.m[0].ToBuffer(col0);
		useInstead.m[1].ToBuffer(col1);
		useInstead.m[2].ToBuffer(col2);
	}
	else {
		m[0].ToBuffer(col0);
		m[1].ToBuffer(col1);
		m[2].ToBuffer(col2);
	}

	Out[0][0] = col0[0];
	Out[0][1] = col0[1];
	Out[0][2] = col0[2];

	Out[1][0] = col1[0];
	Out[1][1] = col1[1];
	Out[1][2] = col1[2];

	Out[2][0] = col2[0];
	Out[2][1] = col2[1];
	Out[2][2] = col2[2];


	return 9;
}

const std::string Matrix3::ToString() const {
	char buffer[256];
	size_t size = sprintf_s(buffer, "[%f, %f, %f]\n[%f, %f, %f]\n[%f, %f, %f]",
		m[0][0], m[1][0], m[2][0],
		m[0][1], m[1][1], m[2][1],
		m[0][2], m[1][2], m[2][2]);
	return std::string(buffer, size);
}