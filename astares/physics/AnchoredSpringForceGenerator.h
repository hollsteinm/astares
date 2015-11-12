#ifndef ANCHORED_SPRING_FORCE_GENERATOR_H
#define ANCHORED_SPRING_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"

class Particle;

class AnchoredSpringForceGenerator : public BaseForceGenerator {
public:
	AnchoredSpringForceGenerator(const Vector3& anchor, float springConstant, float restLength);
private:
protected:
	virtual void Tick(float DeltaTime, Particle* particle) override;

	float SpringConstant;
	float RestLength;
	Vector3 Anchor;
};


#endif