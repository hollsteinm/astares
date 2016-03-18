#include "Types.h"

std::ostream& operator << (std::ostream& out, const vector<int8>& arr) {
	out << arr.size() << ' ';
	out.write((char*)arr.data(), arr.size() * sizeof(int8));
	out << ' ';
	return out;
}

std::istream& operator >> (std::istream& in, vector<int8>& arr) {
	size_t size;
	in >> size;
	char* buffer = new char[size];

	if (in.flags() & std::ios::skipws) { in.seekg((int64)in.tellg() + 1); }

	in.read(buffer, size * sizeof(int8));
	arr.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		arr.push_back(buffer[i]);
	}
	delete[] buffer;
	return in;
}

std::ostream& operator << (std::ostream& out, const vector<uint8>& arr) {
	out << arr.size() << ' ';
	out.write((char*)arr.data(), arr.size() * sizeof(uint8));
	out << ' ';
	return out;
}

std::istream& operator >> (std::istream& in, vector<uint8>& arr) {
	size_t size;
	in >> size;
	char* buffer = new char[size];

	if (in.flags() & std::ios::skipws) { in.seekg((int64)in.tellg() + 1); }

	in.read(buffer, size * sizeof(uint8));
	arr.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		arr.push_back(buffer[i]);
	}
	delete[] buffer;
	return in;
}