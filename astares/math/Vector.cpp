#include "Vector.h"


std::ostream& operator<<(std::ostream& out, const Vector2& vec) {
	return out << vec[0] << ' ' << vec[1];
}
std::istream& operator>>(std::istream& in, Vector2& vec) {
	return in >> vec[0] >> vec[1];
}

std::ostream& operator<<(std::ostream& out, const Vector3& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2];
}

std::istream& operator>>(std::istream& in, Vector3& vec) {
	return in >> vec[0] >> vec[1] >> vec[2];
}

std::ostream& operator<<(std::ostream& out, const Vector4& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2] << ' ' << vec[3];
}

std::istream& operator>>(std::istream& in, Vector4& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}

std::ostream& operator<<(std::ostream& out, const Quaternion& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2] << ' ' << vec[3];
}

std::istream& operator>>(std::istream& in, Quaternion& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}