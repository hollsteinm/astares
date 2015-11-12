#ifndef RAY3_H
#define RAY3_H

#include "Vector.h"


struct Ray3 {
	~Ray3();
	Ray3();
	Ray3(const Vector3& origin, const Vector3& direction);
	Ray3(const Vector2& origin, const Vector2& direction);
	Ray3(const Vector3& origin, const Vector2& direction);
	Ray3(const Vector2& origin, const Vector3& direction);

	Vector3 Origin;
	Vector3 Direction;
};


#endif