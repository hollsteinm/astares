#ifndef GRAVITY_FORCE_GENERATOR_H
#define GRAVITY_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"

#include "../math/Vector.h"


class Particle;

class GravityForceGenerator : public BaseForceGenerator {
public:
	GravityForceGenerator(const Vector3& gravity);
private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) override;

	std::vector<Particle*> EffectedParticles;
	Vector3 Gravity;
};


#endif