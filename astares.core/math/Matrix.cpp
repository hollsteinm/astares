#include "Matrix.h"


WriteStream& operator<<(WriteStream& out, const Matrix2& vec) {
	return out << vec[0] << ' ' << vec[1];
}

ReadStream& operator>>(ReadStream& in, Matrix2& vec) {
	return in >> vec[0] >> vec[1];
}

WriteStream& operator<<(WriteStream& out, const Matrix3& vec) {
	return out << vec.m[0] << ' ' << vec.m[1] << ' ' << vec.m[2];
}

ReadStream& operator>>(ReadStream& in, Matrix3& vec) {
	return in >> vec.m[0] >> vec.m[1] >> vec.m[2];
}

WriteStream& operator<<(WriteStream& out, const Matrix4& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2] << ' ' << vec[3];
}

ReadStream& operator>>(ReadStream& in, Matrix4& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}