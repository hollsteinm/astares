#include "BungeeSpringForceGenerator.h"

#include "Particle.h"

BungeeSpringForceGenerator::BungeeSpringForceGenerator(const Vector3& position, f32 springConstant, f32 restLength) :
	SpringForceGenerator(position, springConstant, restLength)
{

}

void BungeeSpringForceGenerator::Tick(f32 DeltaTime, Particle* particle) {
	Vector3 force = particle->GetPosition();
	force -= Position;
	f32 magnitude = force.GetLength();

	if (magnitude <= RestLength) {
		return;
	}
	else {
		magnitude = SpringConstant * (magnitude - RestLength);
		force.Normalize();
		force *= -magnitude;
		particle->AddForce(force);
	}
}