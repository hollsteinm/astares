#include "Ray2.h"

Ray2::~Ray2() {
}

Ray2::Ray2() :
	Origin(Vector2()),
	Direction(Vector2())
{
}

Ray2::Ray2(const Vector2& origin, const Vector2& direction) :
	Origin(origin),
	Direction(direction)
{
}