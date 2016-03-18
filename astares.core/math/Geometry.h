#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Plane.h"
#include "Ray2.h"
#include "Ray3.h"
#include "Box.h"
#include "Sphere.h"
#include "Hull.h"

ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Plane& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Plane& p);
ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Ray2& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Ray2& p);
ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Ray3& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Ray3& p);
ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Box& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Box& p);
ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Sphere& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Sphere& p);
ASTARESCORE_API WriteStream& operator<<(WriteStream& out, Hull& p);
ASTARESCORE_API ReadStream& operator>>(ReadStream& in, Hull& p);


#endif