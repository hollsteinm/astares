#include "GraphicsAsset.h"

GraphicsAsset::GraphicsAsset() {
	CTOR_REGISTER(GraphicsAsset)
}

GraphicsAsset::~GraphicsAsset(){

}

REFLECTION_BEGIN(GraphicsAsset)
	PARENT(Asset)
REFLECTION_END(GraphicsAsset)