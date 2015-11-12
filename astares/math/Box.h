#ifndef BOX_H
#define BOX_H

#include "Vector.h"

struct Box {
	Box(const Vector3& center, const Vector3& halfSize);
	Box(const Vector3& center);
	Box();

	Vector3 Center;
	Vector3 HalfSize;
};


#endif