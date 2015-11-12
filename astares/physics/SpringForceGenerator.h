#ifndef SPRING_FORCE_GENERATOR_H
#define SPRING_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"

class Particle;

class SpringForceGenerator : public BaseForceGenerator {
public:
	SpringForceGenerator(const Vector3& position, float springConstant, float restLength);

	void SetPosition(const Vector3& newPosition);
private:
protected:
	virtual void Tick(float DeltaTime, Particle* particle) override;

	float SpringConstant;
	float RestLength;
	Vector3 Position;
};


#endif