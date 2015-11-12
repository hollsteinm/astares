#ifndef BUNGEE_SPRING_FORCE_GENERATOR_H
#define BUNGEE_SPRING_FORCE_GENERATOR_H

#include "SpringForceGenerator.h"


class Particle;

class BungeeSpringForceGenerator : public SpringForceGenerator {
public:
	BungeeSpringForceGenerator(const Vector3& position, float springConstant, float restLength);

private:
protected:
	virtual void Tick(float DeltaTime, Particle* particle) override;
};



#endif