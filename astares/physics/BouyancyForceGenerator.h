#ifndef BOUYANCY_FORCE_GENERATOR_H
#define BOUYANCY_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"


class Particle;

class BouyancyForceGenerator : public BaseForceGenerator {
public:
	BouyancyForceGenerator(float maxDepth, float volume, float height, float density);
private:
protected:
	virtual void Tick(float DeltaTime, Particle* particle) override;

	float MaxDepth;
	float Volume;
	float Height;
	float Density;
};



#endif