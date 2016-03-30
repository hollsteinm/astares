#include "Transform.h"
#include "Vector.h"
#include <cmath>

Transform::Transform() {

}

Transform::~Transform() {

}

Transform& Transform::SnapTo(const Vector3& position, const Vector3& rotation, const Vector3& scale) {
	return *this;
}

Matrix4 Transform::TranslationMatrixFromVector(const Vector3& transform) {
	return Matrix4(Vector4(1.0f),
		Vector4(0.0f, 1.0f),
		Vector4(0.0f, 0.0f, 1.0f),
		Vector4(transform[0], transform[1], transform[2], 1.0f));
}

Matrix4 Transform::RotationMatrixFromVector(const Vector3& transform) {
	f32 Cx = std::cosf(transform[0]);
	f32 Cy = std::cosf(transform[1]);
	f32 Cz = std::cosf(transform[2]);

	f32 Sx = std::sinf(transform[0]);
	f32 Sy = std::sinf(transform[1]);
	f32 Sz = std::sinf(transform[2]);

	f32 CyCz = Cy * Cz;
	f32 SxSyCz = Sx * Sy * Cz;
	f32 CxSz = Cx * Sz;
	f32 CxSyCz = Cx * Sy * Cz;
	f32 SxSz = Sx * Sz;
	f32 CySz = Cy * Sz;
	f32 SxSySz = Sx * Sy * Sz;
	f32 CxCz = Cx * Cz;
	f32 CxSySz = Cx * Sy * Sz;
	f32 SxCz = Sx * Cz;
	f32 SxCy = Sx * Cy;
	f32 CxCy = Cx * Sy;

	return Matrix4(
		Vector4(Vector3(CyCz, SxSyCz + CxCz, -CxSyCz + SxSz)),
		Vector4(Vector3(-CySz, -SxSySz + CxCz, CxSySz + SxCz)),
		Vector4(Vector3(Sy, -SxCy, CxCy)),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4 Transform::ScaleMatrixFromVector(const Vector3& transform) {
	return Matrix4(
		Vector4(transform[0]),
		Vector4(0.0f, transform[1]),
		Vector4(0.0f, 0.0f, transform[2]),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f));
}

const Vector3 Transform::GetUp() const {
	return Vector3();
}

const Vector3 Transform::GetRight() const {
	return Vector3();
}

const Vector3 Transform::GetForward() const {
	return Vector3();
}

Matrix4 Transform::GetTransform() const {
	return TranslationMatrixFromVector(Position);
}

Matrix4 Transform::GetRotation() const {
	return ScaleMatrixFromVector(Rotation);
}

Matrix4 Transform::GetScale() const {
	return ScaleMatrixFromVector(Scale);
}

Vector3 Transform::TranslateVector(const Vector3& vector) const {
	Vector4 result = GetTransform() * Vector4(vector[0], vector[1], vector[2], 1.0f);
	return Vector3(result[0], result[1], result[2]);
}

Vector3 Transform::RotateVector(const Vector3& rotation) const {
	Vector4 result = GetRotation() * Vector4(rotation[0], rotation[1], rotation[2], 1.0f);
	return Vector3(result[0], result[1], result[2]);
}

Vector3 Transform::ScaleVector(const Vector3& scale) const {
	Vector4 result = GetScale() * Vector4(scale[0], scale[1], scale[2], 1.0f);
	return Vector3(result[0], result[1], result[2]);
}

Transform& Transform::SetParent(Transform* NewParent) {
	if (Parent.get() != NewParent) {
		Parent = std::shared_ptr<Transform>(NewParent);
	}
	return *this;
}

Matrix4 Transform::GetWorldMatrix() const {
	if (Parent) {
		return Parent->GetTransform() * Parent->GetRotation() * Parent->GetScale() *
			GetTransform() * GetRotation() * GetScale();
	}
	else {
		return GetLocalMatrix();
	}
}

Matrix4 Transform::GetLocalMatrix() const {
	return GetTransform() * GetRotation() * GetScale();
}

Transform& Transform::TranslateTransform(const Vector3& translation) {
	Position = TranslateVector(translation);
	return *this;
}

Transform& Transform::RotateTransform(const Vector3& rotation) {
	Rotation = RotateVector(rotation);
	return *this;
}

Transform& Transform::ScaleTransform(const Vector3& scale) {
	Scale = ScaleVector(scale);
	return *this;
}

Vector3 Transform::PositionVector() const { return Position; }
Vector3 Transform::RotationVector() const { return Rotation; }
Vector3 Transform::ScaleVector() const { return Scale; }

Vector3& Transform::PositionVector() { return Position; }
Vector3& Transform::RotationVector() { return Rotation; }
Vector3& Transform::ScaleVector() { return Scale; }

WriteStream& operator<<(WriteStream& out, const Transform& in) 
{
	return out << in.Position << in.Rotation << in.Scale; //TODO:parent
}

ReadStream& operator>>(ReadStream& in, Transform& out)
{
	return in >> out.Position >> out.Rotation >> out.Scale; //TODO:parent
}