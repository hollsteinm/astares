#include "BouyancyForceGenerator.h"
#include "Particle.h"

BouyancyForceGenerator::BouyancyForceGenerator(float maxDepth, float volume, float height, float density) :
	MaxDepth(maxDepth),
	Volume(volume),
	Height(height),
	Density(density)
{

}

void BouyancyForceGenerator::Tick(float DeltaTime, Particle* particle) {
	float depth = particle->GetPosition()[UP];

	if (depth >= Height + MaxDepth) {
		return;
	}
	else{
		Vector3 force;

		if (depth <= Height - MaxDepth) {
			force[UP] = Density * Volume;
			particle->AddForce(force);
		}
		else {
			force[UP] = Density * Volume * (depth - MaxDepth - Height) / 2.0f * MaxDepth;
			particle->AddForce(force);
		}
	}
}