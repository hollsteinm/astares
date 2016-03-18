#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "GameComponent.h"
#include "../math/Transform.h"

class TransformComponent : public GameComponent {
public:
	TransformComponent();
	~TransformComponent();
private:
protected:
	Transform ComponentTransform;
};

#endif