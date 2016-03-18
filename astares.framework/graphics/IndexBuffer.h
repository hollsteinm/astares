#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "../core/Types.h"

struct IndexBuffer {
	std::vector<int64> Indices;

	static const size_t IndexElementSize;

	friend std::ostream& operator<<(std::ostream& out, IndexBuffer& self);
	friend std::istream& operator>>(std::istream& in, IndexBuffer& self);
};

#endif