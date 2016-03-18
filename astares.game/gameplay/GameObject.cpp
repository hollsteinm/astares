#include "GameObject.h"
#include "GameComponent.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {
	Components.clear();
}