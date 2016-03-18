#ifndef FORCE_GENERATOR_H
#define FORCE_GENERATOR_H

#include "IPhysicsTickable.h"

class Particle;

struct IForceGenerator : public IPhysicsTickable {
	virtual ~IForceGenerator() {}

	virtual void Add(Particle* particle) = 0;
	virtual void Remove(Particle* particle) = 0;
	virtual void Clear() = 0;

protected:
	IForceGenerator(){}
	IForceGenerator(const IForceGenerator& other){}
};


#endif