#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "../core/Array.h"
struct VertexBuffer {
	Array<float> Vertices;
	Array<float> UVs;
	Array<float> Normals;
	Array<float> Tangents;
	Array<float> Binormals;
	Array<float> Colors;

	static const size_t VertexElementSize;

	friend std::ostream& operator<<(std::ostream& out, VertexBuffer& self);
	friend std::istream& operator>>(std::istream& in, VertexBuffer& self);
};

#endif