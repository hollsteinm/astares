#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include "../reflection/Reflection.h"

enum class UpdateType {
	Tick,
	Render,
	Physics,
	Audio,
	Collision,
	Network
};

struct ComponentTickConfig {
	bool bTicks;
	bool bRenders;
	bool bPhsyics;
	bool bAudio;
	bool bCollsion;
	bool bNetwork;

	ComponentTickConfig();

	friend std::ostream& operator<<(std::ostream& out, ComponentTickConfig& self);
	friend std::istream& operator>>(std::istream& in, ComponentTickConfig& self);

	int Pack() const;
	void Unpack(int value);
};

TYPE(ComponentTickConfig)

DECL_CLASS_BASE(GameComponent) {
	DECL_BODY(GameComponent)

	GameComponent(Object* owner);

	virtual void StartPlay();

	void Update(float DeltaTime, UpdateType updateType);

	virtual void TickUpdate(float DeltaTime);
	virtual void RenderUpdate(float DeltaTime);
	virtual void PhysicsUpdate(float DeltaTime);
	virtual void AudioUpdate(float DeltaTime);
	virtual void CollisionUpdate(float DeltaTime);
	virtual void NetworkUpdate(float DeltaTime);

	virtual void EndPlay();

	void SetActive(bool NewActive);

	bool IsActive() const;

	bool DoesTick() const;
	bool DoesRender() const;
	bool DoesPhysics() const;
	bool DoesAudio() const;
	bool DoesCollision() const;
	bool DoesNetwork() const;

	const ObjectPtr<Object>& GetOwner() const;
private:
	ObjectPtr<Object> Owner;

protected:
	ComponentTickConfig TickConfig;
	bool bActive;
};
#endif