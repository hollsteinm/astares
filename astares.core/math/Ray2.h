#ifndef LINE2_H
#define LINE2_H

#include "Vector.h"


struct Vector2;

struct ASTARESCORE_API Ray2 {
	~Ray2();
	Ray2();
	Ray2(const Vector2& origin, const Vector2& direction);

	Vector2 Origin;
	Vector2 Direction;
};


#endif