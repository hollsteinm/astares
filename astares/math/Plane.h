#ifndef PLANE_H
#define PLANE_H

#include "Vector.h"

struct Plane {
	~Plane();
	Plane(const Vector2& normal, float offset);
	Plane(const Vector3& normal, float offset);

	Vector3 Normal;
	float Offset;
};

#endif