#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "../core/Types.h"
struct VertexBuffer {
	std::vector<f32> Vertices;
	std::vector<f32> UVs;
	std::vector<f32> Normals;
	std::vector<f32> Tangents;
	std::vector<f32> Binormals;
	std::vector<f32> Colors;

	static const size_t VertexElementSize;

	friend std::ostream& operator<<(std::ostream& out, VertexBuffer& self);
	friend std::istream& operator>>(std::istream& in, VertexBuffer& self);
};

#endif