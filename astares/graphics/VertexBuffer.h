#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "../core/Array.h"
struct VertexBuffer {
	ObjectArray<float> Vertices;
	ObjectArray<float> UVs;
	ObjectArray<float> Normals;
	ObjectArray<float> Tangents;
	ObjectArray<float> Binormals;
	ObjectArray<float> Colors;

	static const size_t VertexElementSize;

	friend std::ostream& operator<<(std::ostream& out, VertexBuffer& self);
	friend std::istream& operator>>(std::istream& in, VertexBuffer& self);
};

#endif