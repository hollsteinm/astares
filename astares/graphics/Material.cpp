#include "Material.h"

Material::Material() {
	CTOR_REGISTER(Material)
}

Material::~Material() {

}

REFLECTION_BEGIN(Material)
	PARENT(GraphicsAsset)
REFLECTION_END(Material)