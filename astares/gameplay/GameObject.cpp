#include "GameObject.h"
#include "GameComponent.h"

GameObject::GameObject() {
	CTOR_REGISTER(GameObject)
}

GameObject::~GameObject() {
	Components.clear();
}

REFLECTION_BEGIN(GameObject)
	PARENT(Object)
	FIELD(ObjectArray<ObjectPtr<GameComponent>>, Components)
REFLECTION_END(GameObject)