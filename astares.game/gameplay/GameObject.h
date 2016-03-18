#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../reflection/Reflection.h"
#include <vector>
#include "GameComponent.h"


class GameObject : public Object {
public:
	GameObject();
	virtual ~GameObject();

private:
	std::vector<std::shared_ptr<GameComponent>> Components;
};

#endif