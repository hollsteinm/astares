#include "Matrix.h"


std::ostream& operator<<(std::ostream& out, Matrix2& vec) {
	return out << vec[0] << vec[1];
}

std::istream& operator>>(std::istream& in, Matrix2& vec) {
	return in >> vec[0] >> vec[1];
}

std::ostream& operator<<(std::ostream& out, Matrix3& vec) {
	return out << vec.m[0] << vec.m[1] << vec.m[2];
}

std::istream& operator>>(std::istream& in, Matrix3& vec) {
	return in >> vec.m[0] >> vec.m[1] >> vec.m[2];
}

std::ostream& operator<<(std::ostream& out, Matrix4& vec) {
	return out << vec[0] << vec[1] << vec[2] << vec[3];
}

std::istream& operator>>(std::istream& in, Matrix4& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}