#include "Plane.h"

Plane::~Plane() {
}

Plane::Plane(const Vector2& normal, f32 offset) :
	Normal(normal),
	Offset(offset)
{
}

Plane::Plane(const Vector3& normal, f32 offset) :
	Normal(normal),
	Offset(offset)
{
}