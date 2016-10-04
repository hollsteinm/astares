#include "Ray3.h"
#include "Math.h"

using namespace astares;

Ray3::~Ray3() {
}

Ray3::Ray3() :
	Origin(Vector3()),
	Direction(Vector3())
{
}

Ray3::Ray3(const Vector3& origin, const Vector3& direction) :
	Origin(origin),
	Direction(direction)
{
}

Ray3::Ray3(const Vector2& origin, const Vector2& direction) :
	Origin(origin),
	Direction(direction)
{
}

Ray3::Ray3(const Vector3& origin, const Vector2& direction) :
	Origin(origin),
	Direction(direction)
{
}

Ray3::Ray3(const Vector2& origin, const Vector3& direction) :
	Origin(origin),
	Direction(direction)
{
}