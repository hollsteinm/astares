#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Plane.h"
#include "Ray2.h"
#include "Ray3.h"
#include "Box.h"
#include "Sphere.h"
#include "Hull.h"

ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Plane& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Plane& p);
ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Ray2& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Ray2& p);
ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Ray3& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Ray3& p);
ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Box& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Box& p);
ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Sphere& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Sphere& p);
ASTARESCORE_API std::ostream& operator<<(std::ostream& out, Hull& p);
ASTARESCORE_API std::istream& operator>>(std::istream& in, Hull& p);


#endif