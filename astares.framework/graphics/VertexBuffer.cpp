#include "VertexBuffer.h"
#include "../serialization/ArrayHelper.h"


const size_t VertexBuffer::VertexElementSize = sizeof(f32);

std::ostream& operator<<(std::ostream& out, VertexBuffer& self) {
	ArrayHelper::Serialize(self.Binormals, out);
	ArrayHelper::Serialize(self.Colors, out);
	ArrayHelper::Serialize(self.Normals, out);
	ArrayHelper::Serialize(self.Tangents, out);
	ArrayHelper::Serialize(self.UVs, out);
	ArrayHelper::Serialize(self.Vertices, out);
	return out;
}

std::istream& operator>>(std::istream& in, VertexBuffer& self) {
	ArrayHelper::Deserialize(self.Binormals, in);
	ArrayHelper::Deserialize(self.Colors, in);
	ArrayHelper::Deserialize(self.Normals, in);
	ArrayHelper::Deserialize(self.Tangents, in);
	ArrayHelper::Deserialize(self.UVs, in);
	ArrayHelper::Deserialize(self.Vertices, in);
	return in;
}