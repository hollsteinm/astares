#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"

template <typename T>
class ObjectArray : public std::vector<T> {
public:
	friend std::ostream& operator<<(std::ostream& out, ObjectArray<T>& self) {
		out << self.size() << ' ';
		for (auto elem : self) {
			out << elem;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, ObjectArray<T>& self) {
		unsigned int size = 0;
		in >> size;
		self.resize(size);
		for (unsigned int i = 0; i < size; ++i) {
			T obj;
			in >> obj;
			self[i] = obj;
		}

		return in;
	}
};

#endif