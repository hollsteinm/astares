#ifndef BASE_FORCE_GENERATOR_H
#define BASE_FORCE_GENERATOR_H

#include "IForceGenerator.h"
#include <vector>


class Particle;

class BaseForceGenerator : public IForceGenerator {
public:
	virtual void Add(Particle* particle) override;
	virtual void Remove(Particle* particle) override;
	virtual void Tick(f32 DeltaTime) override;
	virtual void Clear() override;
private:
	std::vector<Particle*> EffectedParticles;

protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) = 0;
};

#endif