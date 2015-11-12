#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../reflection/Reflection.h"
#include "../core/Array.h"
#include "GameComponent.h"


DECL_CLASS_BASE(GameObject) {
	DECL_BODY(GameObject)
public:

	template<typename T>
	T* GetComponent() const {
		unsigned long desiredType = TYPEOF(T);
		for (auto CompPtr : Components) {
			if (CompPtr.IsValid() && CompPtr.Get()->GetTypeId() == desiredType) {
				return CompPtr.Get();
			}
		}
		return nullptr;
	}

	template<typename T>
	bool TryGetComponent(T* OutComponent) const {
		OutComponent = GetComponent<T>();
		return OutComponent != nullptr;
	}

protected:
	template<typename T>
	T* CreateComponent() {
		Components.push_back(ObjectPtr<GameComponent>(new T()));
		return (T*)Components.back().Get();
	}

	template<typename T>
	bool TryCreateComponent(T* InComponent) {
		InComponent = CreateComponent<T>();
		return InComponent != nullptr;
	}

	void DestroyComponent(GameComponent* component);

private:
	ObjectArray<ObjectPtr<GameComponent>> Components;
};

#endif