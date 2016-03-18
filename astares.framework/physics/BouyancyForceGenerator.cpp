#include "BouyancyForceGenerator.h"
#include "Particle.h"

BouyancyForceGenerator::BouyancyForceGenerator(f32 maxDepth, f32 volume, f32 height, f32 density) :
	MaxDepth(maxDepth),
	Volume(volume),
	Height(height),
	Density(density)
{

}

void BouyancyForceGenerator::Tick(f32 DeltaTime, Particle* particle) {
	f32 depth = particle->GetPosition()[_UP];

	if (depth >= Height + MaxDepth) {
		return;
	}
	else{
		Vector3 force;

		if (depth <= Height - MaxDepth) {
			force[_UP] = Density * Volume;
			particle->AddForce(force);
		}
		else {
			force[_UP] = Density * Volume * (depth - MaxDepth - Height) / 2.0f * MaxDepth;
			particle->AddForce(force);
		}
	}
}