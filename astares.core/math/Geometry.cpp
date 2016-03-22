#include "Geometry.h"

WriteStream& operator<<(WriteStream& out, const Plane& p) {
	return out << p.Normal << ' ' << p.Offset;
}

ReadStream& operator>>(ReadStream& in, Plane& p) {
	return in >> p.Normal >> p.Offset;
}

WriteStream& operator<<(WriteStream& out, const Ray2& p) {
	return out << p.Direction << ' ' << p.Origin;
}

ReadStream& operator>>(ReadStream& in, Ray2& p) {
	return in >> p.Direction >> p.Origin;
}

WriteStream& operator<<(WriteStream& out, const Ray3& p) {
	return out << p.Direction << ' ' << p.Origin;
}

ReadStream& operator>>(ReadStream& in, Ray3& p) {
	return in >> p.Direction >> p.Origin;
}

WriteStream& operator<<(WriteStream& out, const Box& p) {
	return out << p.Center << ' ' << p.HalfSize;
}

ReadStream& operator>>(ReadStream& in, Box& p) {
	return in >> p.Center >> p.HalfSize;
}

WriteStream& operator<<(WriteStream& out, const Sphere& p) {
	return out << p.Center << ' ' << p.Radius;
}

ReadStream& operator>>(ReadStream& in, Sphere& p) {
	return in >> p.Center >> p.Radius;
}

WriteStream& operator<<(WriteStream& out, const Hull& p) {
	int32 size = p.Points.size();
	out << size << ' ';
	for (auto v : p.Points) {
		out << v << ' ';
	}
	return out;
}

ReadStream& operator>>(ReadStream& in, Hull& p) {
	int32 size = 0;
	in >> size;
	p.Points.reserve(size);
	for (int32 i = 0; i < size; ++i) {
		Vector3 next;
		in >> next;
		p.Points.push_back(next);
	}
	return in;
}