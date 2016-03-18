#include "Vector.h"


WriteStream& operator<<(WriteStream& out, const Vector2& vec) {
	return out << vec[0] << ' ' << vec[1];
}
ReadStream& operator>>(ReadStream& in, Vector2& vec) {
	return in >> vec[0] >> vec[1];
}

WriteStream& operator<<(WriteStream& out, const Vector3& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2];
}

ReadStream& operator>>(ReadStream& in, Vector3& vec) {
	return in >> vec[0] >> vec[1] >> vec[2];
}

WriteStream& operator<<(WriteStream& out, const Vector4& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2] << ' ' << vec[3];
}

ReadStream& operator>>(ReadStream& in, Vector4& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}

WriteStream& operator<<(WriteStream& out, const Quaternion& vec) {
	return out << vec[0] << ' ' << vec[1] << ' ' << vec[2] << ' ' << vec[3];
}

ReadStream& operator>>(ReadStream& in, Quaternion& vec) {
	return in >> vec[0] >> vec[1] >> vec[2] >> vec[3];
}