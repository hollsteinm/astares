#ifndef IPHYSICS_TICKABLE_H
#define IPHYSICS_TICKABLE_H

#include "../core/Types.h"

struct IPhysicsTickable {
	virtual ~IPhysicsTickable() {}
	virtual void Tick(f32 DeltaTime) = 0;
protected:
	IPhysicsTickable() {}
	IPhysicsTickable(const IPhysicsTickable& other) {}
};


#endif