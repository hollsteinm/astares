#ifndef BUNGEE_SPRING_FORCE_GENERATOR_H
#define BUNGEE_SPRING_FORCE_GENERATOR_H

#include "SpringForceGenerator.h"


class Particle;

class BungeeSpringForceGenerator : public SpringForceGenerator {
public:
	BungeeSpringForceGenerator(const Vector3& position, f32 springConstant, f32 restLength);

private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) override;
};



#endif