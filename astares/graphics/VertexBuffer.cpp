#include "VertexBuffer.h"


const size_t VertexBuffer::VertexElementSize = sizeof(float);

std::ostream& operator<<(std::ostream& out, VertexBuffer& self) {
	return out 
		<< self.Binormals << ' '
		<< self.Colors << ' '
		<< self.Normals << ' '
		<< self.Tangents << ' '
		<< self.UVs << ' '
		<< self.Vertices;
}

std::istream& operator>>(std::istream& in, VertexBuffer& self) {
	return in 
		>> self.Binormals 
		>> self.Colors 
		>> self.Normals 
		>> self.Tangents 
		>> self.UVs 
		>> self.Vertices;
}