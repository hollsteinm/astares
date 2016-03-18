#include "Geometry.h"

std::ostream& operator<<(std::ostream& out, Plane& p) {
	return out << p.Normal << ' ' << p.Offset;
}

std::istream& operator>>(std::istream& in, Plane& p) {
	return in >> p.Normal >> p.Offset;
}

std::ostream& operator<<(std::ostream& out, Ray2& p) {
	return out << p.Direction << ' ' << p.Origin;
}

std::istream& operator>>(std::istream& in, Ray2& p) {
	return in >> p.Direction >> p.Origin;
}

std::ostream& operator<<(std::ostream& out, Ray3& p) {
	return out << p.Direction << ' ' << p.Origin;
}

std::istream& operator>>(std::istream& in, Ray3& p) {
	return in >> p.Direction >> p.Origin;
}

std::ostream& operator<<(std::ostream& out, Box& p) {
	return out << p.Center << ' ' << p.HalfSize;
}

std::istream& operator>>(std::istream& in, Box& p) {
	return in >> p.Center >> p.HalfSize;
}

std::ostream& operator<<(std::ostream& out, Sphere& p) {
	return out << p.Center << ' ' << p.Radius;
}

std::istream& operator>>(std::istream& in, Sphere& p) {
	return in >> p.Center >> p.Radius;
}

std::ostream& operator<<(std::ostream& out, Hull& p) {
	int32 size = p.Points.size();
	out << size << ' ';
	for (auto v : p.Points) {
		out << v << ' ';
	}
	return out;
}

std::istream& operator>>(std::istream& in, Hull& p) {
	int32 size = 0;
	in >> size;
	p.Points.resize(size);
	for (int32 i = 0; i < size; ++i) {
		Vector3 next;
		in >> next;
		p.Points.push_back(next);
	}
	return in;
}