#include "BaseForceGenerator.h"
#include "Particle.h"

void BaseForceGenerator::Add(Particle* particle) {
	for (auto p : EffectedParticles) {
		if (p == particle) return;
	}

	EffectedParticles.push_back(particle);
}

void BaseForceGenerator::Remove(Particle* particle) {
	for (auto iter = EffectedParticles.begin(); iter != EffectedParticles.end(); ++iter) {
		if (*iter == particle) {
			EffectedParticles.erase(iter);
			return;
		}
	}
}

void BaseForceGenerator::Tick(f32 DeltaTime) {
	for (auto particle : EffectedParticles) {
		if (!particle->IsInfiniteMass())
		{
			Tick(DeltaTime, particle);
		}
	}
}

void BaseForceGenerator::Clear() {
	EffectedParticles.clear();
}