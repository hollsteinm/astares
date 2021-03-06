#ifndef BASE_FORCE_GENERATOR_H
#define BASE_FORCE_GENERATOR_H

#include "IForceGenerator.h"
#include "../core/Array.h"



class Particle;

class BaseForceGenerator : public IForceGenerator {
public:
	virtual void Add(Particle* particle) override;
	virtual void Remove(Particle* particle) override;
	virtual void Tick(float DeltaTime) override;
	virtual void Clear() override;
private:
	Array<Particle*> EffectedParticles;

protected:
	virtual void Tick(float DeltaTime, Particle* particle) = 0;
};

#endif