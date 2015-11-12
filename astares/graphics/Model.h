#ifndef MODEL_H
#define MODEL_H

#include "GraphicsAsset.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"

DECL_CLASS(Model) : public GraphicsAsset {
	DECL_BODY(Model)

public:
	IndexBuffer iBuff;
	VertexBuffer vBuff;

};


#endif