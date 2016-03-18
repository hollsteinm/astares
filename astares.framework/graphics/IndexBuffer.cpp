#include "IndexBuffer.h"
#include "../serialization/ArrayHelper.h"

const size_t IndexBuffer::IndexElementSize = sizeof(long);

std::ostream& operator<<(std::ostream& out, IndexBuffer& self) {
	ArrayHelper::Serialize(self.Indices, out);
	return out;
}

std::istream& operator>>(std::istream& in, IndexBuffer& self) {
	ArrayHelper::Deserialize(self.Indices, in);
	return in;
}