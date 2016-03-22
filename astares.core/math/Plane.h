#ifndef PLANE_H
#define PLANE_H

#include "Vector.h"

struct ASTARESCORE_API Plane {
	~Plane();
	Plane(const Vector2& normal, const f32& offset);
	Plane(const Vector3& normal, const f32& offset);

	Vector3 Normal;
	f32 Offset;
};

#endif