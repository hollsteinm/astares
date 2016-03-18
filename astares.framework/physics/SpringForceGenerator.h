#ifndef SPRING_FORCE_GENERATOR_H
#define SPRING_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"

class Particle;

class SpringForceGenerator : public BaseForceGenerator {
public:
	SpringForceGenerator(const Vector3& position, f32 springConstant, f32 restLength);

	void SetPosition(const Vector3& newPosition);
private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) override;

	f32 SpringConstant;
	f32 RestLength;
	Vector3 Position;
};


#endif