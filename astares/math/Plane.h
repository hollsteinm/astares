#ifndef PLANE_H
#define PLANE_H

#include "Vector.h"

struct Plane {
	~Plane();
	Plane(const Vector2& normal, f32 offset);
	Plane(const Vector3& normal, f32 offset);

	Vector3 Normal;
	f32 Offset;
};

#endif