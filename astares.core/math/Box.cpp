#include "Box.h"

using namespace astares;

Box::Box(const Vector3& center, const Vector3& halfSize) :
	Center(center),
	HalfSize(halfSize)
{

}

Box::Box(const Vector3& center) :
	Center(center),
	HalfSize()
{

}

Box::Box() : 
	Center(),
	HalfSize()
{

}