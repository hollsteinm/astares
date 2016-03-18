#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include "../object/Object.h"

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

	int32 Pack() const;
	void Unpack(int32 value);
};

class GameComponent : public Object {

public:
	GameComponent(Object* owner);
	GameComponent();
	virtual ~GameComponent();

	virtual void StartPlay();

	void Update(f32 DeltaTime, UpdateType updateType);

	virtual void TickUpdate(f32 DeltaTime);
	virtual void RenderUpdate(f32 DeltaTime);
	virtual void PhysicsUpdate(f32 DeltaTime);
	virtual void AudioUpdate(f32 DeltaTime);
	virtual void CollisionUpdate(f32 DeltaTime);
	virtual void NetworkUpdate(f32 DeltaTime);

	virtual void EndPlay();

	void SetActive(bool NewActive);

	bool IsActive() const;

	bool DoesTick() const;
	bool DoesRender() const;
	bool DoesPhysics() const;
	bool DoesAudio() const;
	bool DoesCollision() const;
	bool DoesNetwork() const;

	const std::weak_ptr<Object> GetOwner() const;
private:
	std::shared_ptr<Object> Owner;

protected:
	ComponentTickConfig TickConfig;
	bool bActive;
};
#endif