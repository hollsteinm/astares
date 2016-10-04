#include "Plane.h"

using namespace astares;

Plane::Plane()
	:Normal( 1.0f, 1.0f, 1.0f ),
	Offset(0.0f)
{

}

Plane::~Plane() {
}

Plane::Plane(const Vector2& normal, const f32& offset) :
	Normal(normal),
	Offset(offset)
{
}

Plane::Plane(const Vector3& normal, const f32& offset) :
	Normal(normal),
	Offset(offset)
{ 
}