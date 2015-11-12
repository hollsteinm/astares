#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.h"


struct Sphere {
	Sphere(const Vector3& center, const float& radius);
	Sphere(const Vector3& center);
	Sphere();

	Vector3 Center;
	float Radius;
};



#endif