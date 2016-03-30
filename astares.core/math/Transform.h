#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix.h"
#include "Vector.h"

static const Vector3 Up = Vector3(0.0f, 1.0f, 0.0f);
static const Vector3 Right = Vector3(1.0f, 0.0f, 0.0f);
static const Vector3 Forward = Vector3(0.0f, 0.0f, 1.0f);

class ASTARESCORE_API Transform;
DECL_CORE_STL_PTR(Transform)

class Transform{
public:
	Transform();
	~Transform();

	Transform& SnapTo(const Vector3& position, const Vector3& rotation, const Vector3& scale);

	const Vector3 GetUp() const;
	const Vector3 GetRight() const;
	const Vector3 GetForward() const;

	static Matrix4 TranslationMatrixFromVector(const Vector3& transform);
	static Matrix4 RotationMatrixFromVector(const Vector3& transform);
	static Matrix4 ScaleMatrixFromVector(const Vector3& transform);

	Matrix4 GetTransform() const;
	Matrix4 GetRotation() const;
	Matrix4 GetScale() const;

	Matrix4 GetWorldMatrix() const;
	Matrix4 GetLocalMatrix() const;

	Vector3 TranslateVector(const Vector3& vector) const;
	Vector3 RotateVector(const Vector3& rotation) const;
	Vector3 ScaleVector(const Vector3& scale) const;

	Transform& TranslateTransform(const Vector3& translation);
	Transform& RotateTransform(const Vector3& rotation);
	Transform& ScaleTransform(const Vector3& scale);

	Transform& SetParent(Transform* NewParent);

	Vector3 PositionVector() const;
	Vector3 RotationVector() const;
	Vector3 ScaleVector() const;

	Vector3& PositionVector();
	Vector3& RotationVector();
	Vector3& ScaleVector();

	friend ASTARESCORE_API WriteStream& operator<<(WriteStream& out, const Transform& in);
	friend ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Transform& out);

private:
protected:
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	std::shared_ptr<Transform> Parent;

};


#endif