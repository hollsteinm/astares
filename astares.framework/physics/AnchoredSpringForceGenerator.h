#ifndef ANCHORED_SPRING_FORCE_GENERATOR_H
#define ANCHORED_SPRING_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"

class Particle;

class AnchoredSpringForceGenerator : public BaseForceGenerator {
public:
	AnchoredSpringForceGenerator(const Vector3& anchor, f32 springConstant, f32 restLength);
private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) override;

	f32 SpringConstant;
	f32 RestLength;
	Vector3 Anchor;
};


#endif