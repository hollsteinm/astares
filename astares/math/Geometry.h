#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Plane.h"
#include "Ray2.h"
#include "Ray3.h"
#include "Box.h"
#include "Sphere.h"
#include "Hull.h"

std::ostream& operator<<(std::ostream& out, Plane& p);
std::istream& operator>>(std::istream& in, Plane& p);

std::ostream& operator<<(std::ostream& out, Ray2& p);
std::istream& operator>>(std::istream& in, Ray2& p);

std::ostream& operator<<(std::ostream& out, Ray3& p);
std::istream& operator>>(std::istream& in, Ray3& p);

std::ostream& operator<<(std::ostream& out, Box& p);
std::istream& operator>>(std::istream& in, Box& p);

std::ostream& operator<<(std::ostream& out, Sphere& p);
std::istream& operator>>(std::istream& in, Sphere& p);

std::ostream& operator<<(std::ostream& out, Hull& p);
std::istream& operator>>(std::istream& in, Hull& p);


#endif