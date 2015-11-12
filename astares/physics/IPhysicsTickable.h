#ifndef IPHYSICS_TICKABLE_H
#define IPHYSICS_TICKABLE_H

struct IPhysicsTickable {
	virtual ~IPhysicsTickable() {}
	virtual void Tick(float DeltaTime) = 0;
protected:
	IPhysicsTickable() {}
	IPhysicsTickable(const IPhysicsTickable& other) {}
};


#endif