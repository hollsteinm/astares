#include "Model.h"

Model::Model() {
	CTOR_REGISTER(Model)
}

Model::~Model() {

}

REFLECTION_BEGIN(Model)
	PARENT(GraphicsAsset)
	FIELD(IndexBuffer, iBuff)
	FIELD(VertexBuffer, vBuff)
REFLECTION_END(Model)