#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "GameComponent.h"
#include "../math/Transform.h"

DECL_CLASS(TransformComponent) : public GameComponent {
	DECL_BODY(TransformComponent)
public:
private:
protected:
	Transform ComponentTransform;
};

#endif