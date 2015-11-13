#include "TransformComponent.h"

TransformComponent::TransformComponent() {
	CTOR_REGISTER(TransformComponent)
}

TransformComponent::~TransformComponent() {

}

REFLECTION_BEGIN(TransformComponent)
	PARENT(GameComponent)
	FIELD(Transform, ComponentTransform)
REFLECTION_END(TransformComponent)