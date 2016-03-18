#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.h"


struct ASTARESCORE_API Sphere {
	Sphere(const Vector3& center, const f32& radius);
	Sphere(const Vector3& center);
	Sphere();

	Vector3 Center;
	f32 Radius;
};



#endif