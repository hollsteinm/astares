#include "IndexBuffer.h"

const size_t IndexBuffer::IndexElementSize = sizeof(long);

std::ostream& operator<<(std::ostream& out, IndexBuffer& self) {
	return out << self.Indices;
}

std::istream& operator>>(std::istream& in, IndexBuffer& self) {
	return in >> self.Indices;
}