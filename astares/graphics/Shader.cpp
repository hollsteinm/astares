#include "Shader.h"

Shader::Shader() {
	CTOR_REGISTER(Shader)
}

Shader::~Shader() {

}

REFLECTION_BEGIN(Shader)
	PARENT(GraphicsAsset)
REFLECTION_END(Shader)