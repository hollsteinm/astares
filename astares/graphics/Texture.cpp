#include "Texture.h"

Texture::Texture() {
	CTOR_REGISTER(Texture)
}

Texture::~Texture() {

}

REFLECTION_BEGIN(Texture)
	PARENT(GraphicsAsset)
REFLECTION_END(Texture)