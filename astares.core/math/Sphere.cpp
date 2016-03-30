#include "Sphere.h"

Sphere::Sphere(const Vector3& center, const f32& radius) : Center(center), Radius(radius)
{

}

Sphere::Sphere(const Vector3& center) : Center(center), Radius(1.0f)
{

}

Sphere::Sphere() : Center(), Radius(1.0f)
{

}