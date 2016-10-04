#ifndef SPHERE_H
#define SPHERE_H

#include "../core/Types.h"
#include "Vector.h"

namespace astares {

	struct ASTARESCORE_API Sphere {
		Sphere(const Vector3& center, const f32& radius);
		Sphere(const Vector3& center);
		Sphere();

		Vector3 Center;
		f32 Radius;
	};

}

#endif