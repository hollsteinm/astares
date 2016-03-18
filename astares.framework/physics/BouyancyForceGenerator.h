#ifndef BOUYANCY_FORCE_GENERATOR_H
#define BOUYANCY_FORCE_GENERATOR_H

#include "BaseForceGenerator.h"
#include "../math/Vector.h"


class Particle;

class BouyancyForceGenerator : public BaseForceGenerator {
public:
	BouyancyForceGenerator(f32 maxDepth, f32 volume, f32 height, f32 density);
private:
protected:
	virtual void Tick(f32 DeltaTime, Particle* particle) override;

	f32 MaxDepth;
	f32 Volume;
	f32 Height;
	f32 Density;
};



#endif