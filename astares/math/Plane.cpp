#include "Plane.h"

Plane::~Plane() {
}

Plane::Plane(const Vector2& normal, float offset) :
	Normal(normal),
	Offset(offset)
{
}

Plane::Plane(const Vector3& normal, float offset) :
	Normal(normal),
	Offset(offset)
{
}