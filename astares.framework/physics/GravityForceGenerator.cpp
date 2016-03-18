#include "GravityForceGenerator.h"
#include "Particle.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& gravity) :
	Gravity(gravity)
{

}

void GravityForceGenerator::Tick(f32 DeltaTime, Particle* particle) {
	particle->AddForce(Gravity * particle->GetMass());
}