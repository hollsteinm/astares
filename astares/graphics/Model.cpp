#include "Model.h"

Model::Model() {
	CTOR_REGISTER(Model)
}

Model::~Model() {

}

REFLECTION_BEGIN(Model)
	PARENT(GraphicsAsset)
	PROPERTY(IndexBuffer, iBuff)
	PROPERTY(VertexBuffer, vBuff)
REFLECTION_END(Model)