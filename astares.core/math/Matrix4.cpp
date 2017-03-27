#include "Matrix4.h"
#include "Math.h"

using namespace astares;

const Matrix4 Matrix4::Identity = Matrix4(	Vector4(1.0f, 0.0f, 0.0f, 0.0f),
											Vector4(0.0f, 1.0f, 0.0f, 0.0f),
											Vector4(0.0f, 0.0f, 1.0f, 0.0f),
											Vector4(0.0f, 0.0f, 0.0f, 1.0f));

Matrix4::Matrix4() {
	*this = Identity;
}

Matrix4::Matrix4(const Matrix4& other) {
	m[0] = other[0];
	m[1] = other[1];
	m[2] = other[2];
	m[3] = other[3];
}

Matrix4::~Matrix4() {

}

Matrix4::Matrix4(const Vector4& col0) {
	m[0] = col0;
}

Matrix4::Matrix4(const Vector4& col0, const Vector4& col1) :
	Matrix4(col0)
{
	m[1] = col1;
}

Matrix4::Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2) :
	Matrix4(col0, col1)
{
	m[2] = col2;
}

Matrix4::Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2, const Vector4& col3) :
	Matrix4(col0, col1, col2)
{
	m[3] = col3;
}

Matrix4::Matrix4(const Vector3& col0) :
	Matrix4(Vector4(col0))
{
}

Matrix4::Matrix4(const Vector3& col0, const Vector3& col1) :
	Matrix4(Vector4(col0), Vector4(col1))
{

}
Matrix4::Matrix4(const Vector3& col0, const Vector3& col1, const Vector3& col2) :
	Matrix4(Vector4(col0), Vector4(col1), Vector4(col2))
{
}

Matrix4::Matrix4(const Vector3& col0, const Vector3& col1, const Vector3& col2, const Vector3& col3) :
	Matrix4(Vector4(col0), Vector4(col1), Vector4(col2), Vector4(col3))
{
}

Matrix4::Matrix4(const Vector2& col0) :
	Matrix4(Vector4(col0))
{
}

Matrix4::Matrix4(const Vector2& col0, const Vector2& col1) :
	Matrix4(Vector4(col0), Vector4(col1))
{
}

Matrix4::Matrix4(const Vector2& col0, const Vector2& col1, const Vector2& col2) :
	Matrix4(Vector4(col0), Vector4(col1), Vector4(col2))
{
}

Matrix4::Matrix4(const Vector2& col0, const Vector2& col1, const Vector2& col2, const Vector2& col3) :
	Matrix4(Vector4(col0), Vector4(col1), Vector4(col2), Vector4(col3))
{
}

Matrix4& Matrix4::Transpose() {
	Matrix4 temp(*this);

	m[0][0] = temp[0][0];	m[1][0] = temp[0][1];	m[2][0] = temp[0][2];	m[3][0] = temp[0][3];

	m[0][1] = temp[1][0];	m[1][1] = temp[1][1];	m[2][1] = temp[1][2];	m[3][1] = temp[1][3];

	m[0][2] = temp[2][0];	m[1][2] = temp[2][1];	m[2][2] = temp[2][2];	m[3][2] = temp[2][3];

	m[0][3] = temp[3][0];	m[1][3] = temp[3][1];	m[2][3] = temp[3][2];	m[3][3] = temp[3][3];

	return *this;
}

Matrix4& Matrix4::Inverse() {
	f32 det = GetDeterminant();
	if (Math::LargerThanAlmostZero(det))
		return Adjoint() *= (1 / det);
	else return *this;
}

Matrix4& Matrix4::Adjoint() {
	return CofactorMatrix().Transpose();
}

Matrix3 Matrix4::GetMinor(int32 col, int32 row) const {
	int32 col0, col1, col2, row0, row1, row2 = 0;

	switch (col)
	{
	case 0:
		col0 = 1;
		col1 = 2;
		col2 = 3;
		break;
	case 1:
		col0 = 0;
		col1 = 2;
		col2 = 3;
		break;
	case 2:
		col0 = 0;
		col1 = 1;
		col2 = 3;
		break;
	case 3:
		col0 = 0;
		col1 = 1;
		col2 = 2;
		break;
	}

	switch (row)
	{
	case 0:
		row0 = 1;
		row1 = 2;
		row2 = 3;
		break;
	case 1:
		row0 = 0;
		row1 = 2;
		row2 = 3;
		break;
	case 2:
		row0 = 0;
		row1 = 1;
		row2 = 3;
		break;
	case 3:
		row0 = 0;
		row1 = 1;
		row2 = 2;
		break;
	}

	return Matrix3(Vector3(m[col0][row0], m[col0][row1], m[col0][row2]),
		Vector3(m[col1][row0], m[col1][row1], m[col1][row2]),
		Vector3(m[col2][row0], m[col2][row1], m[col2][row2]));
}

Matrix4& Matrix4::CofactorMatrix() {
	Matrix4 temp(*this);
	for (int32 row = 0; row < 4; ++row) {
		for (int32 col = 0; col < 4; ++col) {
			temp[col][row] = GetCofactor(col, row);
		}
	}

	*this = temp;
	return *this;
}

Matrix4 Matrix4::GetTranspose() const {
	return Matrix4(*this).Transpose();
}

Matrix4 Matrix4::GetInverse() const {
	return Matrix4(*this).Inverse();
}

Matrix4 Matrix4::GetAdjoint() const {
	return Matrix4(*this).Adjoint();
}

Matrix4 Matrix4::GetCofactorMatrix() const {
	return Matrix4(*this).CofactorMatrix();
}

f32 Matrix4::GetDeterminant() const {
	f32 det2_11 = m[0][0] * m[1][1] - m[1][0] * m[0][1];
	f32 det2_12 = m[0][0] * m[2][1] - m[2][0] * m[0][1];
	f32 det2_13 = m[0][0] * m[3][1] - m[3][0] * m[0][1];

	f32 det2_112 = m[1][0] * m[2][1] - m[2][0] * m[1][1];
	f32 det2_113 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
	f32 det2_123 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

	f32 det3_201012 = m[0][2] * det2_112 - m[1][2] * det2_12 + m[2][2] * det2_11;
	f32 det3_201013 = m[0][2] * det2_113 - m[1][2] * det2_13 + m[3][2] * det2_11;
	f32 det3_201023 = m[0][2] * det2_123 - m[2][2] * det2_13 + m[3][2] * det2_12;

	f32 det3_201123 = m[1][2] * det2_123 - m[2][2] * det2_113 + m[3][2] * det2_112;

	return (-det3_201123 * m[0][3] + det3_201023 * m[1][3] - det3_201013 * m[2][3] + det3_201012 * m[3][3]);
}

f32 Matrix4::GetCofactor(int32 col, int32 row) {
	static const f32 signs[4][4] = {
		1.0f, -1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f, -1.0f, 1.0f
	};
	return GetMinor(col, row).GetDeterminant() * signs[row][col];
}

Matrix4 Matrix4::operator+(const Matrix4& other) const {
	return Matrix4(m[0] + other[0], m[1] + other[1], m[2] + other[2]);
}

Matrix4 Matrix4::operator-(const Matrix4& other) const {
	return Matrix4(m[0] - other[0], m[1] - other[1], m[2] - other[2]);
}

Matrix4 Matrix4::operator*(f32 a) const {
	return Matrix4(m[0] * a, m[1] * a, m[2] * a);
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Vector4 row0 = Vector4(m[0][0], m[1][0], m[2][0], m[3][0]);
	Vector4 row1 = Vector4(m[0][1], m[1][1], m[2][1], m[3][1]);
	Vector4 row2 = Vector4(m[0][2], m[1][2], m[2][2], m[3][2]);
	Vector4 row3 = Vector4(m[0][3], m[1][3], m[2][3], m[3][3]);

	return Matrix4(Vector4(row0.GetDot(other[0]), row0.GetDot(other[1]), row0.GetDot(other[2]), row0.GetDot(other[3])),
		Vector4(row1.GetDot(other[0]), row1.GetDot(other[1]), row1.GetDot(other[2]), row1.GetDot(other[3])),
		Vector4(row2.GetDot(other[0]), row2.GetDot(other[1]), row2.GetDot(other[2]), row2.GetDot(other[3])),
		Vector4(row3.GetDot(other[0]), row3.GetDot(other[1]), row3.GetDot(other[2]), row3.GetDot(other[3])));
}

Matrix4 Matrix4::operator/(f32 b) const {
	return Matrix4(m[0] / b, m[1] / b, m[2] / b);
}

Matrix4& Matrix4::operator+=(const Matrix4& other) {
	m[0] += other[0];
	m[1] += other[1];
	m[2] += other[2];
	m[3] += other[3];
	return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& other) {
	m[0] -= other[0];
	m[1] -= other[1];
	m[2] -= other[2];
	m[3] -= other[3];
	return *this;
}

Matrix4& Matrix4::operator*=(f32 a) {
	m[0] *= a;
	m[1] *= a;
	m[2] *= a;
	m[3] *= a;
	return *this;
}

Matrix4& Matrix4::operator/=(f32 b) {
	m[0] /= b;
	m[1] /= b;
	m[2] /= b;
	m[3] /= b;
	return *this;
}

Vector4 Matrix4::operator*(const Vector4& vec) const {
	return Vector4(
			m[0][0] * vec[0] + m[1][0] * vec[1] + m[2][0] * vec[2] + m[3][0] * vec[3], 
			m[0][1] * vec[0] + m[1][1] * vec[1] + m[2][1] * vec[2] + m[3][1] * vec[3],
			m[0][2] * vec[0] + m[1][2] * vec[1] + m[2][2] * vec[2] + m[3][2] * vec[3],
			m[0][3] * vec[0] + m[1][3] * vec[1] + m[2][3] * vec[2] + m[3][3] * vec[3]
		);
}

Vector4& operator*=(Vector4& vec, const Matrix4& mat) {
	vec = mat * vec;
	return vec;
}

Vector4 operator*(const Vector4& vec, const Matrix4& mat) {
	return mat * vec;
}

Matrix4 operator*(const f32 f, const Matrix4& mat) {
	return mat * f;
}

bool Matrix4::operator==(const Matrix4& other) const {
	return (m[0] == other[0]) & (m[1] == other[1]) & (m[2] == other[2]) & (m[3] == other[3]);
}

bool Matrix4::operator!=(const Matrix4& other) const {
	return (m[0] != other[0]) & (m[1] != other[1]) & (m[1] != other[1]) & (m[1] != other[1]);
}

Vector4& Matrix4::operator[](int32 col) {
	return m[col];
}

const Vector4& Matrix4::operator[](int32 col) const {
	return m[col];
}

f32& Matrix4::operator()(int32 row, int32 col) {
	return m[col][row];
}

const f32& Matrix4::operator()(int32 row, int32 col) const {
	return m[col][row];
}

int32 Matrix4::ToBuffer(f32 Out[4][4], bool transpose) {
	f32 col0[4];
	f32 col1[4];
	f32 col2[4];
	f32 col3[4];

	if (transpose) {
		Matrix4 useInstead = GetTranspose();
		useInstead.m[0].ToBuffer(col0);
		useInstead.m[1].ToBuffer(col1);
		useInstead.m[2].ToBuffer(col2);
		useInstead.m[3].ToBuffer(col3);
	}
	else {
		m[0].ToBuffer(col0);
		m[1].ToBuffer(col1);
		m[2].ToBuffer(col2);
		m[3].ToBuffer(col3);
	}

	Out[0][0] = col0[0];
	Out[0][1] = col0[1];
	Out[0][2] = col0[2];
	Out[0][3] = col0[3];

	Out[1][0] = col1[0];
	Out[1][1] = col1[1];
	Out[1][2] = col1[2];
	Out[1][3] = col1[3];

	Out[2][0] = col2[0];
	Out[2][1] = col2[1];
	Out[2][2] = col2[2];
	Out[2][3] = col2[3];

	Out[3][0] = col3[0];
	Out[3][1] = col3[1];
	Out[3][2] = col3[2];
	Out[3][3] = col3[3];

	return 16;
}

const astares::cstring Matrix4::ToString() const {
	static char buffer[256];
	size_t size = sprintf_s(buffer, "[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]\n[%f, %f, %f, %f]",
		m[0][0], m[1][0], m[2][0], m[3][0],
		m[0][1], m[1][1], m[2][1], m[3][1],
		m[0][2], m[1][2], m[2][2], m[3][2],
		m[0][3], m[1][3], m[2][3], m[3][3]);
	return buffer;
}