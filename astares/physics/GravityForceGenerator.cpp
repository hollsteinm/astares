#include "GravityForceGenerator.h"
#include "Particle.h"

GravityForceGenerator::GravityForceGenerator(const Vector3& gravity) :
	Gravity(gravity)
{

}

void GravityForceGenerator::Tick(float DeltaTime, Particle* particle) {
	particle->AddForce(Gravity * particle->GetMass());
}